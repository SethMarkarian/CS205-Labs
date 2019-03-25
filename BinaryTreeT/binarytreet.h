#ifndef BINARYTREET_H
#define BINARYTREET_H

/**
 * @brief The node struct is helpful to construct a node
 */
struct node {
    /**
     * @brief val
     */
    int val;

    /**
     * @brief left pointer to left node
     */
    node * left;

    /**
     * @brief right pointer to right node
     */
    node * right;
};

template <class T>
class BinaryTreeT
{
    /**
     * @brief destroy leaf
     * @param leaf to be destroyed
     */
    void destroy(node * leaf) {
        if(leaf != nullptr) {
            destroy(leaf->left);
            destroy(leaf->right);
            delete leaf;
        }
    }

    /**
     * @brief insertNode w/ key and new node
     * @param new_key value in node
     * @param leaf new node
     */
    void insertNode(T new_key, node * leaf) {
        if(new_key.compare(leaf->val) >= 0) { //right node
            if(leaf->right != nullptr) { //not empty
                insert(new_key, leaf->right);
            }
            else { //empty
                leaf->right = new node;
                leaf->right->val = new_key;
                leaf->right->left = nullptr;
                leaf->right->right = nullptr;
            }
        }
        else if(new_key.compare(leaf->val) < 0) { //left node
            if(leaf->left != nullptr) { //not empty
                insert(new_key, leaf->left);
            }
            else { //empty
                leaf->left = new node;
                leaf->left->val = new_key;
                leaf->left->left = nullptr;
                leaf->left->right = nullptr;
            }
        }
    }

    /**
     * @brief search for a node
     * @param new_key to be searched
     * @param leaf find leaf
     * @return found node
     */
    node * search(T new_key, node * leaf);

    /**
     * @brief root of tree
     */
    node * root;
public:

    /**
     * @brief BinaryTreeT empty constructor
     */
    BinaryTreeT() {
        root = nullptr;
    }

    /**
      * @brief ~BinaryTreeT destructor
      */
    ~BinaryTreeT() {
        destroy();
    }

    /**
     * @brief insert new key
     * @param new_key to be inserted
     */
    void  insert(T new_key) {
        if(root != nullptr) {
            insert(new_key, root);
        }
        else {
            root = new node;
            root->val = new_key;
            root->left = nullptr;
            root->right = nullptr;
        }
    }

    /**
     * @brief search for a node with the new key
     * @param new_key search for key
     * @return node
     */
    node * search(T new_key) {
        return search(new_key, root);
    }

    /**
     * @brief destroy tree
     */
    void destroy() {
        destroy(root);
    }
};

#endif // BINARYTREET_H
