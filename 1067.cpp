#include <bits/stdc++.h>
using namespace std;
 
struct Dir {
    map<string, Dir*> subdirectories;
};
 
Dir root;
 
void addDirectory(string path) {
    Dir* current = &root;
    string directory;
    stringstream ss(path);
 
    // Parse each directory name separated by backslash
    while (getline(ss, directory, '\\')) {
        // Create directory if it doesn't exist
        if (current->subdirectories.find(directory) == current->subdirectories.end()) {
            current->subdirectories[directory] = new Dir();
        }
        // Move to the subdirectory
        current = current->subdirectories[directory];
    }
}
 
void printTree(Dir* dir, int depth = 0) {
    // Print each subdirectory with proper indentation
    for (auto& pair : dir->subdirectories) {
        string dirName = pair.first;
        Dir* subdir = pair.second;
 
        // Print indentation (depth * 1 space)
        for (int i = 0; i < depth; i++) {
            cout << " ";
        }
        cout << dirName << "\n";
 
        // Recursively print subdirectories
        printTree(subdir, depth + 1);
    }
}
 
int main() {
    int n;
    cin >> n;
 
    // Read each file path and add to tree
    for (int i = 0; i < n; i++) {
        string path;
        cin >> path;
        addDirectory(path);
    }
 
    // Print the entire directory tree
    printTree(&root);
 
    return 0;
}
