#pragma once
#include <iostream>

namespace List {

    template<class LISTTYPE>

    class List {
    private:

        template <class NODETYPE>
        class Node {
        private:
            Node<NODETYPE>* pNext;
            Node<NODETYPE>* pPrev;
            NODETYPE Info;

        public:
            Node<NODETYPE>() {pNext = NULL; pPrev = NULL;}
            ~Node<NODETYPE>() {pNext = NULL; pPrev = NULL;}
            void setNext(Node<NODETYPE>* pNextIn) {pNext = pNextIn;}
            void setPrev(Node<NODETYPE>* pPrevIn) {pPrev = pPrevIn;}
            void setInfo(const NODETYPE& pInfoIn) {Info = pInfoIn;}
            Node<NODETYPE>* getNext() {return pNext;}
            Node<NODETYPE>* getPrev() {return pPrev;}
            NODETYPE& getInfo() {return Info;}
        };

        Node<LISTTYPE>* pFirst;
        Node<LISTTYPE>* pLast;
        int listSize;


    public:
        List();
        ~List();

        void clear();

        void pushBack(const LISTTYPE& Info);
        void pushFront(const LISTTYPE& Info);
        void removeElement(const LISTTYPE& element);
        void removeAndDeleteElement(const LISTTYPE& element);

        LISTTYPE* getFirst();
        LISTTYPE* getLast();
        int getSize();
        LISTTYPE operator[](int pos);

        class iterator {
            friend class List;
        private:
            Node<LISTTYPE>* element;
            iterator(Node<LISTTYPE>* el){element = el;}
        public:
            iterator(const iterator& other){element = other.element;}
            ~iterator(){element = NULL;}
            LISTTYPE& operator*(){return element->getInfo();}
            bool operator==(const iterator& other) {return element == other.element;}
            bool operator!=(const iterator& other) {return !(*this == other);}
            iterator& operator++() {if (element != NULL) element = element->getNext(); return *this;}
            iterator operator++(int) {Node<LISTTYPE>* ret = element; if (element != NULL)element = element->getNext(); return iterator(ret);}
        };

        iterator begin() {return iterator(pFirst);}
        iterator end() {return iterator(pLast);}
    };


    template <class LISTTYPE>
    List<LISTTYPE>::List() {
        pFirst = NULL;
        pLast = NULL;
        listSize = 0;
    }

    template <class LISTTYPE>   List<LISTTYPE>::~List() {
        clear();
    }

    template <class LISTTYPE>
    void List<LISTTYPE>::clear() {

        while (pFirst != NULL) {
            Node<LISTTYPE>* aux = pFirst->getNext();
            if (aux) {
                if (aux->getInfo())
                    delete (aux->getInfo());
            }
            delete pFirst;
            pFirst = aux;
            listSize--;
        }
        pFirst = NULL;
        pLast = NULL;

    }

    template <typename LISTTYPE>
    void List<LISTTYPE>::pushBack(const LISTTYPE& Info) {
        if(Info) {
            if (pFirst == nullptr) {
                Node<LISTTYPE>* aux = new Node<LISTTYPE>();
                aux->setInfo(Info);
                pFirst = aux;
                pLast = aux;
            } else {
                Node<LISTTYPE>* aux = new Node<LISTTYPE>();
                aux->setInfo(Info);
                pLast->setNext(aux);
                aux->setPrev(pLast);
                pLast = aux;
            }
            listSize++;
        }
        else {
            std::cout << "ERROR: Trying to add a NULL object on List<LISTTYPE>::pushFront method. Operation not succeeded." << std::endl;
        }
    }

    template <typename LISTTYPE>
    void List<LISTTYPE>::pushFront(const LISTTYPE& Info) {
        if(Info) {
            if (pFirst == nullptr) {
                Node<LISTTYPE>* aux = new Node<LISTTYPE>();
                aux->setInfo(Info);
                pFirst = aux;
                pLast = aux;
            } else {
                Node<LISTTYPE>* aux = new Node<LISTTYPE>();
                aux->setInfo(Info);
                pFirst->setPrev(aux);
                aux->setNext(pFirst);
                pFirst = aux;
            }
            listSize++;
        }
        else
            std::cout << "ERROR: Trying to add a NULL object on List<LISTTYPE>::pushFront method. Operation not succeeded." << std::endl;
    }

    template <typename LISTTYPE>
    void List<LISTTYPE>::removeAndDeleteElement(const LISTTYPE &element) {
        if (pFirst == NULL) {
            return;
        }
        else {
            Node<LISTTYPE>* aux = pFirst;
            while (aux != NULL && aux->getInfo() != element) {
                aux = aux->getNext();
            }

            if (aux == NULL)
                return;

            if (aux->getPrev() != NULL)
                aux->getPrev()->setNext(aux->getNext());
            else
                pFirst = aux->getNext();

            if (aux->getNext() != NULL)
                aux->getNext()->setPrev(aux->getPrev());
            else
                pLast = aux->getPrev();

            delete aux->getInfo();
            delete aux;
            listSize--;
        }
    }

    template <typename LISTTYPE>
    void List<LISTTYPE>::removeElement(const LISTTYPE &element) {
        if (pFirst == NULL) {
            return;
        }
        else {
            Node<LISTTYPE>* aux = pFirst;
            while (aux != NULL && aux->getInfo() != element) {
                aux = aux->getNext();
            }

            if (aux == NULL)
                return;

            if (aux->getPrev() != NULL)
                aux->getPrev()->setNext(aux->getNext());
            else
                pFirst = aux->getNext();

            if (aux->getNext() != NULL)
                aux->getNext()->setPrev(aux->getPrev());
            else
                pLast = aux->getPrev();

            delete aux;
            listSize--;
        }
    }

    template <class LISTTYPE>
    LISTTYPE* List<LISTTYPE>::getFirst() {
        if(pFirst)
            return pFirst->getInfo();
        else
            std::cout<<"ERROR: Trying to get a element on empty list on List<LISTTYPE>::getFirst method. Cannot perform operation."<<std::endl;
    }

    template <class LISTTYPE>
    LISTTYPE* List<LISTTYPE>::getLast() {
        if(pLast)
            return pLast->getInfo();
        else
            std::cout<<"ERROR: Trying to get a element on empty list on List<LISTTYPE>::getLast method. Cannot perform operation."<<std::endl;
    }

    template <class LISTTYPE>
    int List<LISTTYPE>::getSize() {
        return listSize;
    }

    template <class LISTTYPE>
    LISTTYPE List<LISTTYPE>::operator[](int pos) {
        if(pos<listSize || pos>=0) {
            Node<LISTTYPE>* pAux = NULL;
            pAux = pFirst;

            for (int i = 0; i < pos; i++) {
                if (pAux)
                    pAux = pAux->getNext();
            }

            if (pAux == NULL) {
                std::cout << "ERROR: on template operator[] pAux == NULL." << std::endl;
                exit(1);
            }
            return pAux->getInfo();
        }
        else{
            std::cout << "ERROR: Segmentation fault on template list. Exceeded boundaries." << std::endl;
            exit(1);
        }
    }

}