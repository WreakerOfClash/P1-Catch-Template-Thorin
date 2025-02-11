#include <catch2/catch_test_macros.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include "AVL.h"

// Name: Thorin Groth
// UFID: 21975652

using namespace std;

// Test Case #1
TEST_CASE("Invalid Statements for AVL Trees", "[error]") {
	AVLTree tree;

	REQUIRE_THROWS(tree.insert("",100)); // testing adding empty string as key
	REQUIRE_THROWS(tree.remove(1000000)); // testing removing node that doesn't exist
	REQUIRE_THROWS(tree.insert("Test",-50)); // testing negative numbers
	REQUIRE_THROWS(tree.insert("34320",12)); // testing only numbers for key
	REQUIRE_THROWS(tree.insert("Thor1n",100)); // testing invalid key with test and numbers

}

// Test Case #2
TEST_CASE("Inserting and Deleting Large Nodes", "[bulk]") {
	AVLTree tree;
	std::vector<int> vect_vals;

	// adding 200 nodes
	for(int i = 1, i < 200, i++) {
		tree.insert(i);
		vect_vals.pushback(i);
		}

	// removing 15 nodes
	std::vector<int> removeNodes = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 28, 30, 50};
	for(int r : removeNodes) {
		tree.remove(r);
		vect_vals.erase(std::remove(vect_vals.begin(),vect_vals.end(),r),vect_vals.end());
	}

	REQUIRE(tree.inorder() == vect_vals);
}

// Test Case #3
TEST_CASE("Search Functionality", "[search]") {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);

    REQUIRE(tree.find(10) == true);
    REQUIRE(tree.find(20) == true);
    REQUIRE(tree.find(30) == true);
    REQUIRE(tree.find(40) == false);
}

// Test Case #4
TEST_CASE("Tree Balance After Multiple Operations", "[balance]") {
    AVLTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.remove(70);
    tree.remove(30);

    REQUIRE(tree.isBalanced());
}

// Test Case #5
TEST_CASE("Rotating AVL Tree", "[rotation]") {
    AVLTree tree;

    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    REQUIRE(tree.isBalanced());

    tree.insert(40);
    tree.insert(50);
    REQUIRE(tree.isBalanced());

    tree.insert(25);
    REQUIRE(tree.isBalanced());

    tree.insert(45);
    tree.insert(42);
    REQUIRE(tree.isBalanced());
}
