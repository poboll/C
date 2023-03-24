#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class DicTreeNode {
public:
    unordered_map<char, DicTreeNode*> child;
    bool endFlag;
    DicTreeNode() : endFlag(false) {}
};

class StreamChecker {
private:
    string curStr;
    DicTreeNode* root;
    
public:
    StreamChecker(vector<string>& words) : curStr(""), root(new DicTreeNode()) {
        for (const string& word : words) {
            DicTreeNode* rootTmp = root;
            for (int i = word.length() - 1; i >= 0; i--) {
                if (rootTmp->child.find(word[i]) == rootTmp->child.end()) {
                    rootTmp->child[word[i]] = new DicTreeNode();
                }
                rootTmp = rootTmp->child[word[i]];
            }
            rootTmp->endFlag = true;
        }
    }
    
    bool query(char letter) {
        curStr += letter;
        DicTreeNode* rootTmp = root;
        for (int i = curStr.length() - 1; i >= 0; i--) {
            if (rootTmp->child.find(curStr[i]) == rootTmp->child.end()) {
                return false;
            }
            rootTmp = rootTmp->child[curStr[i]];
            if (rootTmp->endFlag == true) {
                return true;
            }
        }
        return false;
    }
};