#include "catch.hpp"
#include "linkedlist.h"
#include "dsstack.h"
#include "adjlist.h"

TEST_CASE("LinkedList class", "[LinkedList]") {
    int element[4] = {1, 2, 3, 4};
    LinkedList<int> test(element[0]);

    REQUIRE(test.getSize() == 1);
    REQUIRE(test.isEmpty() == false);
    REQUIRE(test.contains(1) == true);
    REQUIRE(test.contains(5) == false);

    test.insertAtFront(element[1]);
    REQUIRE(test.getSize() == 2);
    REQUIRE(test.contains(2) == true);

    test.deleteBack();
    REQUIRE(test.contains(1) == false);

    test.insertAtEnd(element[0]);
    REQUIRE(test.getSize() == 2);
    REQUIRE(test.contains(1) == true);

    test.deleteFront();
    REQUIRE(test.contains(2) == false);

    LinkedList<int> test1;
    test1 = test;
    REQUIRE(test1.getSize() == 1);
    REQUIRE(test1.isEmpty() == false);
    REQUIRE(test1.contains(2) == false);
    REQUIRE(test1.contains(5) == false);

    LinkedList<int>::iterator itr;
    itr = test.begin();
    test.insert(itr, element[2]);
    REQUIRE(test.contains(3) == true);
    REQUIRE(test.getSize() == 2);
    test.erase(itr);
    REQUIRE(test.contains(1) == false);
    REQUIRE(test.getSize() == 1);
    test.clear();
    REQUIRE(test.isEmpty() == true);
}

TEST_CASE("Stack class", "[DSStack]") {
    DSStack<int> test;
    test.push(3);
    REQUIRE(test.contains(3) == true);
    test.push(5);
    REQUIRE(test.peek() == 5);
    test.pop();
    REQUIRE(test.contains(5) == false);
    test.pop();
    REQUIRE(test.isEmpty() == true);
}
