//!  Copyright_ [2024] <Kauan Elias Schneider Fank>

#ifndef STRUCTURES_BINARY_TREE_H
#define STRUCTURES_BINARY_TREE_H

#include <stack>
#include <queue>
#include "./array_list.h"

namespace structures {

//! Classe Árvore binária
template<typename T>
class BinaryTree {
 public:
    //! ...
    BinaryTree();
    //! ...
    ~BinaryTree();
    //! ...
    void insert(const T& data);
    //! ...
    void remove(const T& data);
    //! ...
    bool contains(const T& data) const;
    //! ...
    bool empty() const;
    //! ...
    std::size_t size() const;
    //! ...
    ArrayList<T> pre_order() const;
    //! ...
    ArrayList<T> in_order() const;
    //! ...
    ArrayList<T> post_order() const;

    //******************************************************************
    // Prova prática - implementações necessárias:

    // (1) determinação da altura da árvore:
    int height();

    // (2) contagem do número de folhas:
    int leaves();

    // (3) criação de uma lista com o menor (mínimo) e o maior (máximo)
    //     valor da árvore:
    ArrayList<T> limits();

    // (4) criação de uma duplicação, em memória, da árvore:
    BinaryTree<T> clone();

    // (5) remove nós pelo número de seus filhos:
    void filter(int n_child);

    // (6) criação de um nova árvore que tenha todos os valores e a
    //     menor altura possível, ou seja, balanceada com base apenas
    //     no estabelecimento de uma nova ordem de inserção:
    BinaryTree<T> balance();

    //******************************************************************


 private:
    struct Node {
        //! Construtor
        explicit Node(const T& data) :
        data_{data}
        {}

        //! Destrutor
        ~Node() {
            delete left_;
            delete right_;
        }

        T data_;
        Node* left_{nullptr};
        Node* right_{nullptr};

        //! Inserção
        void insert(const T& data) {
            if (data <= data_) {
                if (left_ != nullptr) return left_->insert(data);
                else left_ = new Node(data);
            } else {
                if (right_ != nullptr) return right_->insert(data);
                else right_ = new Node(data);
            }
        }

        //! Remoção
        bool remove(const T& data) {
            if (data_ == data) {
                if (left_ != nullptr && right_ == nullptr) {
                    Node *temp = left_;
                    data_ = temp->data_;
                    right_ = temp->right_;
                    left_ = temp->left_;
                    temp->left_ = nullptr;
                    temp->right_ = nullptr;
                    delete temp;
                } else if (left_ == nullptr && right_ != nullptr) {
                    Node *temp = right_;
                    data_ = temp->data_;
                    right_ = temp->right_;
                    left_ = temp->left_;
                    temp->left_ = nullptr;
                    temp->right_ = nullptr;
                    delete temp;
                } else if (left_ != nullptr && right_ != nullptr) {
                    Node *temp = right_;
                    while (temp->left_ != nullptr) temp = temp->left_;
                    auto aux = temp->data_;
                    remove(temp->data_);
                    data_ = aux;
                } else {
                    // delete this;
                }
                return true;
            } else if (data_ < data) {
                if (left_ != nullptr) return left_->remove(data);
                else return false;
            } else {
                if (right_ != nullptr) return right_->remove(data);
                else return false;
            }
        }

        //! Contém
        bool contains(const T& data) const {
            if (data_ == data) {
                return true;
            } else if (data_ < data) {
                if (left_ != nullptr) {
                    return left_->contains(data_);
                } else {
                    return false;
                }
            } else {  // data_ > data
                if (right_ != nullptr) {
                    return right_->contains(data_);
                } else {
                    return false;
                }
            }
        }

        //! Pré ordem
        void pre_order(ArrayList<T>& v) const {
            v.push_back(data_);
            if (left_ != nullptr)
                left_->pre_order(v);
            if (right_ != nullptr)
                right_->pre_order(v);
        }

        //! Em ordem
        void in_order(ArrayList<T>& v) const {
            if (left_ != nullptr) left_->in_order(v);
			v.push_back(data);
			if (right_ != nullptr) right_->in_order(v);
        }

        //! Pós ordem
        void post_order(ArrayList<T>& v) const {
            if (left_ != nullptr) left_->post_order(v);
			if (right_ != nullptr) right_->post_order(v);
			v.push_back(data);
        }



     private:
        //! Complemento da funcão de remoção
        Node* remove(const T& data, Node* arv, bool& deleted) {
            if (data_ == data) {
                if (left_ != nullptr && right_ == nullptr) {
                    Node *temp = left_;
                    data = temp->data;
                    right_ = temp->right_;
                    left_ = temp->left_;
                    deleted = true;
                    return temp;
                } else if (left_ == nullptr && right_ != nullptr) {
                    Node *temp = right_;
                    data = temp->data;
                    right_ = temp->right_;
                    left_ = temp->left_;
                    deleted = true;
                    return temp;
                } else if (left_ != nullptr && right_ != nullptr) {
                    Node *temp = right_;
                    while (temp->left_ != nullptr) temp = temp->left_;
                    auto aux = temp->data;
                    remove(temp->data);
                    data = aux;
                } else {
                    // delete this;
                    deleted = true;
                }
                return true;
            } else if (data_ < data) {
                if (left_ != nullptr) return left_->remove(data_);
                else {
                    deleted = false;
                    return nullptr;
                }
            } else {
                if (right_ != nullptr) return right_->remove(data_);
                else {
                    deleted = false;
                    return nullptr;
                }
            }
        }

        //! Encontrar o menor
        Node* minimum() {
            if (left_ == nullptr)
                return this;
            return left_->minimum();
        }
    };

    Node* root_{nullptr};
    std::size_t size_{0};
};




//******************************************************************
// Prova prática - implementações necessárias:

//! (1) determinação da altura da árvore:
template<typename T>
int BinaryTree<T>::height() {
    if (root == nullptr) return 0;

    std::stack<pair<Node *, int>> s;
    s.push({root, 1});
    int maior = 0;
    while (!s.empty()) {
        auto e = s.top();
        s.pop();
        if (e.second > maior) maior = e.second;
        if (e.first->left_ != nullptr) s.push({e.first->left_, e.second+1});
        if (e.first->right_ != nullptr) s.push({e.first->right_, e.second+1});
    }
    return maior;
}

//! (2) contagem do número de folhas:
template<typename T>
int BinaryTree<T>::leaves() {
    if (root = nullptr) return 0;

    int count = 0;
    std::stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
        auto e = s.top();
        s.pop();
        if (e->right_ != nullptr) s.push(e->right_);
        if (e->left_ != nullptr) s.push(e->left_);
        if (e->right_ == nullptr && e->left_ == nullptr) count++;
    }
    return count;
}

//! (3) criação de uma lista com o menor (mínimo) e o maior (máximo)
//!     valor da árvore:
template<typename T>
ArrayList<T> BinaryTree<T>::limits() {
    ArrayList<T> L(2);

    if (root == nullptr) {
        L[0] = 0; L[1] = 0;
        return L;
    }

    auto menor = root;
    while (menor->left_ != nullptr) menor = menor->left_;

    auto maior = root;
    while (maior->right_ != nullptr) maior = maior->right_;

    L[0] = menor->data; L[1] = maior->data;

    return L;
}

//! (4) criação de uma duplicação, em memória, da árvore:
template<typename T>
BinaryTree<T> BinaryTree<T>::clone() {
    BinaryTree<T> C;
    if (root == nullptr) return C;
    queue<Node *> q; q.push(root);
    while (!q.empty()) {
        auto e = q.front();
        q.pop();
        C.insert(e->data);
        if (e->left_ != nullptr) q.push(e->left_);
        if (e->right_ != nullptr) q.push(e->right_);
    }
    return C;
}

//! (5) remove nós pelo número de seus filhos:
template<typename T>
void BinaryTree<T>::filter(int n_child) {
    if (root != nullptr) {
        stack<pair<Node *, int>> s;
        int child = 0;
        if (root->left_ != nullptr) child++;
        if (root->right_ != nullptr) child++;
        s.push({root, child});
        while (!s.empty()) {
            auto e = s.top();
            s.pop();
            int child1 = 0, child2 = 0;
            if (e->right_ != nullptr) {
                if (e->right_->right_ != nullptr) child1++;
                if (e->right_->left_ != nullptr) child1++;
                s.push({e->right_, child1});
            } else {
                if (e->left_->right_ != nullptr) child2++;
                if (e->left_->left_ != nullptr) child2++;
                s.push({e->left_, child2});
            }
        }
    }
}

//! (6) criação de um nova árvore que tenha todos os valores e a
//!     menor altura possível, ou seja, balanceada com base apenas
//!     no estabelecimento de uma nova ordem de inserção:
template<typename T>
BinaryTree<T> BinaryTree<T>::balance() {
    BinaryTree<T> B;
    /*
        COLOQUE SEU CÓDIGO AQUI ...
    */
    return B;
}

//******************************************************************



//! Construtor
template<typename T>
BinaryTree<T>::BinaryTree()
{}

//! Destrutor
template<typename T>
BinaryTree<T>::~BinaryTree() {
    delete root_;
}

//! Inserção
template<typename T>
void BinaryTree<T>::insert(const T& data) {
    if (empty()) {
        root_ = new Node(data);
        if (root_ == nullptr)
            throw std::out_of_range("FUll tree!");
    } else {
            root_->insert(data);
    }
    ++size_;
}

// Remoção
template<typename T>
void BinaryTree<T>::remove(const T& data) {
    if (empty())
        throw std::out_of_range("Empty tree");

    if (size() != 1u) {
        if (root_->remove(data))
            --size_;
    } else {
        if (root_->data_ == data) {
            delete root_;
            root_ = nullptr;
            --size_;
        }
    }
}

//! Contém
template<typename T>
bool BinaryTree<T>::contains(const T& data) const {
    if (empty())
        return false;
    return root_->contains(data);
}

//! Vazio
template<typename T>
bool BinaryTree<T>::empty() const {
    return size() == 0;
}

//! Tamanho
template<typename T>
std::size_t BinaryTree<T>::size() const {
    return size_;
}

//! Pré ordem
template<typename T>
ArrayList<T> BinaryTree<T>::pre_order() const {
    ArrayList<T> v{size_};
    if (!empty())
        root_->pre_order(v);
    return v;
}

//! Em ordem
template<typename T>
ArrayList<T> BinaryTree<T>::in_order() const {
    ArrayList<T> v{size_};
    if (!empty())
        root_->in_order(v);
    return v;
}

//! Pós ordem
template<typename T>
ArrayList<T> BinaryTree<T>::post_order() const {
    ArrayList<T> v{size_};
    if (!empty())
        root_->post_order(v);
    return v;
}

}  // namespace structures

#endif
