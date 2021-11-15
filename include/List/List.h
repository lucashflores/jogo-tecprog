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
            NODETYPE* pInfo;

        public:
            Node<NODETYPE>(){}
            ~Node<NODETYPE>(){}
            void setNext(Node<NODETYPE>* pNextIn) {
                pNext = pNextIn;
            }
            void setPrev(Node<NODETYPE>* pPrevIn) {pPrev = pPrevIn;}
            void setInfo(NODETYPE* pInfoIn) {pInfo = pInfoIn;}
            Node<NODETYPE>* getNext() {return pNext;}
            Node<NODETYPE>* getPrev() {return pPrev;}
            NODETYPE* getInfo() {return pInfo;}
        };

        Node<LISTTYPE>* pFirst;
        Node<LISTTYPE>* pLast;
        int listSize;


    public:
        List();
        ~List();
        void clear();
        void pushNode(Node<LISTTYPE>* pNode);
        void pushInfo(LISTTYPE* pInfo);
        LISTTYPE* pull();
        void removeInfo(LISTTYPE* pInfo);
        LISTTYPE* getFirst();
        LISTTYPE* getLast();
        int getSize();
        LISTTYPE* operator[](int pos);

    };


    template <class LISTTYPE>
    List<LISTTYPE>::List(){
        pFirst = NULL;
        pLast = NULL;
        listSize = 0;
    }

    template <class LISTTYPE>
    List<LISTTYPE>::~List(){

    }

    template <class LISTTYPE>
    void List<LISTTYPE>::clear() {

        Node <LISTTYPE>* aux1 = NULL;
        Node <LISTTYPE>* aux2 = NULL;

        aux1 = pFirst;
        aux2 = aux1;

        while(aux1){
            delete (aux1->getInfo());
            aux2 = aux1->getNext();
            delete (aux1);
            aux1 = aux2;
            listSize--;
        }

        pFirst = NULL;
        pLast = NULL;

    }

    template <class LISTTYPE>
    void List<LISTTYPE>::pushNode(Node <LISTTYPE>* pNode) {
        if(pNode){
            if(pFirst){
                pFirst = pNode;
                pLast = pNode;
            }
            else{
                pLast->setNext(pNode);
                pNode->setPrev(pLast);
                pNode->setNext(NULL);
                pLast = pNode;
            }
            listSize++;
        }
        else{
            std::cout<<"ERROR: Trying to add a NULL node on List<LISTTYPE>::pushNode method. Insert not succeeded."<<std::endl;
        }
    }

    template<class LISTTYPE>
    void List<LISTTYPE>::pushInfo(LISTTYPE* pInfo) {
        if(pInfo){
            Node<LISTTYPE>* pAux = NULL;
            pAux = new Node<LISTTYPE>();
            pAux->setInfo(pInfo);
            pushNode(pAux);
        }
        else{
            std::cout << "ERROR: Trying to add a NULL object on List<LISTTYPE>::pushInfo method. Operation not succeeded." << std::endl;
        }
    }

    template <class LISTTYPE>
    LISTTYPE* List<LISTTYPE>::pull(){
        if(pLast) {
            LISTTYPE* info = NULL;
            info = pLast->getInfo();

            delete (pLast->getInfo());
            pLast = pLast->getPrev();
            delete(pLast->getNext());
            listSize--;

            return info;
        }
        else {
            std::cout<<"ERROR: Trying to pull a empty list on List<LISTTYPE>::pull method. Cannot perform operation."<<std::endl;
        }
    }

    template <class LISTTYPE>
    void List<LISTTYPE>::removeInfo(LISTTYPE* pInfo){
        Node<LISTTYPE>* paux = NULL;
        paux = pFirst;
        while (paux != pLast || paux->getInfo() != pInfo) {
            paux = paux->getNext();
        }
        if (paux->getInfo() == pInfo) {
            Node<LISTTYPE>* paux2 = paux->getPrev();
            delete paux->getInfo();
            paux2->setNext(paux->getNext());
            delete paux;
            listSize--;
        }
        paux = NULL;
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
    LISTTYPE* List<LISTTYPE>::operator[](int pos) {
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