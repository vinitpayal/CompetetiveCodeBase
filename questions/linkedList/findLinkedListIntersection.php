<?php
// $ho = fopen('php://stdout', "w");

// fwrite($ho, "Hello");


// fclose($ho);



/* 
Your last C/C++ code is saved below:
#include <iostream>
using namespace std;

int main() {
    cout<<"Hello";
    return 0;
}

/* 
Your last Python code is saved below:
'''
Given pointers to the head nodes of  linked lists that merge together at some point, find the Node where the two lists merge. It is guaranteed that the two head Nodes will be different, and neither will be NULL.

In the diagram below, the two lists converge at Node x:

[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q
'''

 */
 
    
      class llNode{
        
        private $data = null;
        private $nextNode = null;
        
        public function setData($value){
            $this->data = $value;
        }
     
        public function setNextNode($newNode){
            $this->nextNode = $newNode;
        }
          
        public function getData(){
            return $this->data;
        }
          
        public function getNextNode(){
            return $this->nextNode;
        }
    }
    
     class linkedList{
        private $head = null;
        
        public function createNode(){
            return new llNode();
        }
        public function getHead(){
            return $this->head;
        }
        public function setHead($headNode){
            $this->head = $headNode;
        }
        
    }

    $ll1 = new linkedList();
    $ll2 = new linkedList();

    /**
        First Linked List Nodes creation
    **/
    $nl11 = new llNode();
    $nl11->setData('a');

    $nl12 = new llNode();
    $nl12->setData('b');


    $nl13 = new llNode();
    $nl13->setData('c');


    $nl14 = new llNode();
    $nl14->setData('x');


    $nl15 = new llNode();
    $nl15->setData('y');


    $nl16 = new llNode();
    $nl16->setData('z');

    
    /*
        Linking nodes of linked list 1 
    */
    
    $nl11->setNextNode($nl12);
    $nl12->setNextNode($nl13);
    $nl13->setNextNode($nl14);
    $nl14->setNextNode($nl15);
    $nl15->setNextNode($nl16);


    /**
        2nd Linked list nodes creation
    **/
    
    $nl21 = new llNode();
    $nl21->setData('p');

    $nl22 = new llNode();
    $nl22->setData('q');
    
    /*
        2nd linked list node linking
    */

    $nl21->setNextNode($nl22);
    $nl22->setNextNode($nl14);
    
    //Set heads
    $ll1->setHead($nl11);
    $ll2->sethead($nl21);

    $ll1Length = 0;
    $ll2Length = 0;
    
    $ll1Ptr = $ll1->getHead();
    $ll2Ptr = $ll2->getHead();
    


    while($ll1Ptr != null){
        $ll1Length++;
        $ll1Ptr = $ll1Ptr->getNextNode();
    }

    while($ll2Ptr != null){
        $ll2Length++;
        $ll2Ptr = $ll2Ptr->getNextNode();
    }

    $greaterLl = $ll2Length >= $ll1Length ? '2':'1';

    $ll1Head = $ll1->getHead();
    $ll2Head = $ll2->getHead();
    

    if($greaterLl == '2'){
        $Difflen =  $ll2Length - $ll1Length;
        
        $llIndex = 0;
        
        
        while($llIndex < $Difflen){
            $ll2Head = $ll2Head->getNextNode();
            $llIndex++;
        }
    }
    else{
        $Difflen =  $ll1Length - $ll2Length;
        
        $llIndex = 0;
        
        
        while($llIndex < $Difflen){
            $ll1Head = $ll1Head->getNextNode();
            $llIndex++;
        }
    }

    while($ll1Head != $ll2Head && $ll1Head && $ll2Head){
         $ll1Head = $ll1Head->getNextNode();
         $ll2Head = $ll2Head->getNextNode();
    }

    echo "Intersection point is ".$ll1Head->getData();
    

    
     