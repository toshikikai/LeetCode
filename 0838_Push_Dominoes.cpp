#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // Approach 1: Force-based solution
    // Uses two passes to calculate forces from left and right
    string pushDominoes_force(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n, 0);
        
        // Pass from left to right
        int force = 0;
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') {
                force = n;
            } else if (dominoes[i] == 'L') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            forces[i] += force;
        }
        
        // Pass from right to left
        force = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') {
                force = n;
            } else if (dominoes[i] == 'R') {
                force = 0;
            } else {
                force = max(force - 1, 0);
            }
            forces[i] -= force;
        }
        
        // Determine final state
        string result;
        for (int f : forces) {
            if (f > 0) {
                result += 'R';
            } else if (f < 0) {
                result += 'L';
            } else {
                result += '.';
            }
        }
        
        return result;
    }

    // Approach 2: Two-pointer solution
    // Uses two pointers to process segments between falling dominoes
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int i = 0;
        
        while (i < n) {
            // Skip standing dominoes
            while (i < n && dominoes[i] == '.') i++;
            
            if (i == n) break;
            
            // Handle 'L' domino
            if (dominoes[i] == 'L') {
                // Make all dominoes to the left fall left
                int j = i - 1;
                while (j >= 0 && dominoes[j] == '.') {
                    dominoes[j] = 'L';
                    j--;
                }
                i++;
            }
            // Handle 'R' domino
            else {
                // Find the next 'L' or 'R'
                int j = i + 1;
                while (j < n && dominoes[j] == '.') j++;
                
                if (j == n) {
                    // No 'L' found, make all dominoes to the right fall right
                    while (i < n) dominoes[i++] = 'R';
                }
                else if (dominoes[j] == 'R') {
                    // Make all dominoes between two 'R's fall right
                    while (i < j) dominoes[i++] = 'R';
                }
                else {
                    // Found 'L', make dominoes fall towards the middle
                    int left = i + 1;
                    int right = j - 1;
                    while (left < right) {
                        dominoes[left++] = 'R';
                        dominoes[right--] = 'L';
                    }
                    i = j + 1;
                }
            }
        }
        
        return dominoes;
    }

    // Approach 3: Simulation approach
    // Simulates each second of dominoes falling until no more changes
    string pushDominoes_simulation(string dominoes) {
        int n = dominoes.size();
        bool changed = true;
        
        while (changed) {
            changed = false;
            // Create a copy to store next state
            string next = dominoes;
            
            // Process each domino
            for (int i = 0; i < n; i++) {
                if (dominoes[i] == '.') {
                    // Check left neighbor
                    bool leftForce = (i > 0 && dominoes[i-1] == 'R');
                    // Check right neighbor
                    bool rightForce = (i < n-1 && dominoes[i+1] == 'L');
                    
                    // If only one force is acting
                    if (leftForce && !rightForce) {
                        next[i] = 'R';
                        changed = true;
                    } else if (!leftForce && rightForce) {
                        next[i] = 'L';
                        changed = true;
                    }
                    // If both forces are equal, it stays standing
                }
            }
            
            dominoes = next;
        }
        
        return dominoes;
    }
};