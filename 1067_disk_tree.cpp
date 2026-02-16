
#include <bits/stdc++.h>
using namespace std;

struct node{
    
    map<string, node*>sub;//subfoldes 
};
node* root=new node();

void Dir(string path){
    stringstream ss(path);
    //cout<<path<<endl;
    string dir;
    node* current=root;
    
    while(getline(ss,dir,'\\')){
        //cout<<dir<<endl;
        if(current->sub.find(dir)==current->sub.end()){
            current->sub[dir]=new node();
        }
        current=current->sub[dir];
        
    }
    
    
}
void print(node* root,int depth=0){
    for(auto& pair:root->sub){
        for(int i=0;i<depth;i++)cout<<" ";
        cout<<pair.first<<endl;
        print(pair.second,depth+1);
    }
}

int main() {
    int n;
    cin >> n;
 
    // Read each file path and add to tree
  for (int i = 0; i < n; i++) {
        string path;
        cin >> path;
        Dir(path);
    }
 
    // Print the entire directory tree
    //printTree(&root);
    print(root, 0);
    return 0;
}
