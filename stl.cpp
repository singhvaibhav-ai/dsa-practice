#include <bits/stdc++.h>
using namespace std;

void explainPair()
{
    // pair class is inside std library.
    // pair<int, int> pr1 = {2, 8};
    pair<int, int> pr1 = make_pair(2, 8);
    cout << pr1.first << " " << pr1.second << endl;

    pair<int, char> pr2 = make_pair(2, 'b');
    cout << pr2.first << " " << pr2.second << endl;

    pair<pair<int, char>, int> pr3 = {{4, 'h'}, 8};
    cout << pr3.first.second << endl;

    pair<pair<pair<int, int>, char>, int> pr4 = {{{1, 2}, 'h'}, 8};
    cout << pr4.first.first.second << endl;
}

void explainVector()
{
    vector<int> vec;
    vec.push_back(1); // or we can use
    vec.emplace_back(2);
    vec.push_back(0);
    // [1, 2, 0]
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " "; // or
        cout << vec.at(i) << " ";
    }
    cout << endl;

    cout << vec.size() << endl; // prints the size of vec.
    cout << vec.front();        // prints the first element of vec
    cout << vec.back();         // prints the last element of vec.
    vec.pop_back();             // the last element will be popped out.
    vec.erase(vec.begin());     // deletes the 1st element from vec.

    // iterator
    vector<int>::iterator beginItr = vec.begin();
    vector<int>::iterator endItr = vec.end();

    // vec.begin() and vec.end() refer to the memory locations of the first element and just past the last element, respectively — not the elements themselves.

    // if i do
    // endItr = endItr - 1;
    // then i have to write i <= endItr in the loop.
    for (vector<int>::iterator i = beginItr; i != endItr; i++)
    {
        cout << *i << " ";
    }

    cout << endl;
    // or we can also use "auto" in place of "vector<int>::iterator" i.e. Using auto instead of explicitly declaring the iterator type

    for (auto i = vec.begin(); i != vec.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;

    // or we can directly print as well
    for (auto i : vec)
    {
        cout << i << " ";
    }
    cout << endl;

    // reverse iterator
    auto reverseBegin = vec.rbegin(); // points to location of last element
    auto reverseEnd = vec.rend();     // points to location before the first element.

    for (auto i = reverseBegin; i != reverseEnd; i++)
    {
        cout << *i << " "; // this prints the vector in reverse order.
    }
    cout << endl;

    // there are many ways to define a vector.
    vector<int> vec1(5); // it creates a vector containing 5 zeroes.

    vector<int> vec2 = {7, 8}; // it creates a vector containing 7 and 8.
    vec2.push_back(1);
    vec2.emplace_back(2);
    vec2.push_back(0);

    vec2.erase(vec2.begin() + 1, vec2.end() - 1); // deletes all the elements starting from 2nd element to 2nd last element.

    vector<int> dupVec(vec2); // it creates a duplicate of vector vec2
    for (auto i : dupVec)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> dupVec1(vec2.begin() + 2, vec2.end() - 1); // it creates a vector containing the elements from vec2 from 3rd to 2nd last position.
    for (auto i : dupVec1)
    {
        cout << i << " ";
    }
    cout << endl;

    dupVec1.clear(); // it deletes every element.

    vector<int> vec4 = {7, 8, 8, 6, 7};
    vector<int> vec5 = {6, 4};
    swap(vec4, vec5); // swaps vec4 and vec 5.

    for (auto it : vec4)
    {
        cout << it << " ";
    }
    cout << endl;

    vec5.insert(vec5.begin() + 2, 4); // inserts 4 before the third element of vec5.
}

void explainList()
{
    list<int> ls = {6, 7}; // Similar to vector in many functionalities, but also supports push_front()

    ls.push_front(1); // Inserts element at the front. Now ls = {1, 6, 7}

    // Print list elements using range-based for loop
    for (auto it : ls)
    {
        cout << it << " ";
    }
    cout << endl;
}

void explainDeque()
{
    // vector is array-based, while list and deque are based on linked list.
    // deque supports fast insertion/removal from both front and back.

    deque<int> dq = {10, 20, 30};
    dq.push_front(0); // Insert at the beginning
    dq.push_back(40); // Insert at the end

    // Print deque elements
    for (int i : dq)
    {
        cout << i << " ";
    }
    cout << endl;
}

void explainStack()
{
    // LIFO
    stack<int> st;
    st.push(1);
    st.push(7);

    cout << st.size() << endl;
    cout << st.top() << " "; // we can only access the topmost element (7)
    st.pop();                // removes the topmost element(7) so 2nd last element(1) becomes the top most element.
    cout << st.top() << " "; // top most element gets printed i.e. 1
    st.pop();                // removes 1
    // cout << st.top() << " "; // no output as all elements were removed and will give run time error.

    stack<int> st1;
    st1.push(1);
    st1.push(7);
    st1.push(71);
    st1.push(73);
    st1.push(17);
    st1.push(27);

    while (st1.empty() == false)
    {
        cout << st1.top() << " ";
        st1.pop();
    }

    stack<int> st3;
    st3.push(1);
    st3.push(3);
    st3.push(5);
    stack<int> st4;
    st4.push(2);
    st4.push(4);
    st4.push(6);
    swap(st3, st4); // swaps st3 and st4.

    while (st3.empty() == false)
    {
        cout << st3.top() << " ";
        st3.pop();
    }
}

void explainQueue()
{
    // FIFO
    queue<int> q;
    q.push(2);
    q.push(22);
    q.push(23);
    q.push(24);
    while (q.empty() == false)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    cout << q.size() << endl;
    // also swap function is available
}

void explainPQ()
{
    // Stores the highest element at the top
    priority_queue<int> pq;
    pq.push(5);
    pq.push(2);
    pq.push(10);
    pq.push(8);

    // cout << pq.top() << " "; // prints 10
    // pq.pop();                // removes 10
    // cout << pq.top() << " "; // prints 8

    while (pq.empty() == false)
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
    // prints the elements in descenting order

    // for storing smallest element at the top
    priority_queue<int, vector<int>, greater<int>> pq1; // min heap
    // same datatype to be entered in vector and greater which is written outside.
    pq1.push(5);
    pq1.push(2);
    pq1.push(10);
    pq1.push(8);
    while (pq1.empty() == false)
    {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;
    // this will now print in ascending order.
}

void explainSet()
{
    // stores only unique elements and in ascending order
    set<int> st;
    st.insert(2);
    st.insert(21);
    st.insert(21);
    st.insert(21);
    st.insert(12);
    // the set is 2 12 21

    for (auto it : st)
    {
        cout << it << " ";
    }
    cout << endl;
    // prints 2 12 21

    auto it = st.find(12); // iterator to find 12
    if (it != st.end())
    {
        cout << *it; // prints 12 if found. and does nothing if not found.
    }
    cout << endl;

    cout << st.count(21); // returns 1 if the element is present, else returns 0
    cout << endl;

    st.erase(21); // erases 21 from the set.
    for (auto it : st)
    {
        cout << it << " "; // prints 2 12
    }
    cout << endl;

    auto it3 = st.end();
    it3--;         // now it points to last element i.e. memory location of last element.
    st.erase(it3); // erases the last element.
    // we can choose the location from which we have to remove the element.

    set<int> st1;
    st1.insert(2);
    st1.insert(21);
    st1.insert(12);
    st1.insert(211);
    st1.insert(213);
    auto it1 = st1.begin();
    it1++;
    auto it2 = st1.end();
    it2--;
    // st1.erase(it1, it2); // erases elements starting from 2nd place till 2nd last place.
    // for (auto it : st1)
    // {
    //     cout << it << " "; // prints 2 213
    // }
    // cout << endl;

    // lower_bound returns an iterator that points to the first element that is >= number given
    auto it4 = st1.lower_bound(11);  // points to 12
    cout << *it4 << endl;            // prints 12
    auto it5 = st1.lower_bound(214); // points to end() as no element is >= 214
    if (it5 == st1.end())
    {
        cout << "end" << endl;
    }

    // upper_bound returns an iterator that points to the first element that is > number given
    auto it6 = st1.upper_bound(12); // points to 21
    cout << *it6 << endl;           // prints 21
}

void explainMultiSet()
{
    // multiset is similar to set, but it allows duplicate elements.
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    ms.insert(0);
    ms.insert(21);
    ms.insert(21);
    for (auto it : ms)
    {
        cout << it << " "; // prints 0 1 1 1 1 2 21 21
    }
    cout << endl;

    auto it = ms.find(1); // points to the first occurrence of 1

    ms.erase(1); // erases all occurrences of 1
    for (auto it : ms)
    {
        cout << it << " "; // prints 0 2 21 21
    }
    cout << endl;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    // if we want to erase only one occurrence of 1, we can use
    auto it2 = ms.erase(ms.find(1)); // erases only the first occurrence of 1
    for (auto it : ms)
    {
        cout << it << " "; // prints 0 1 1 1 2 21 21
    }
    cout << endl;

    cout << ms.count(1) << endl; // prints 3, as there are three occurrences of 1

    // rest all the functions are same as set.
}

void explainunorderedSet()
{
    // unordered_set is similar to set, but it does not maintain any order of elements.
    unordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(1);
    st.insert(11);
    st.insert(11);
    st.insert(12);
    st.insert(12);
    st.insert(12);

    for (auto it : st)
    {
        cout << it << " "; // prints elements in no particular order
    }
    cout << endl;

    auto it = st.find(11); // unordered_set is used because of its less time complexity for search operations like O(1) or O(N) in worst case.
    if (it != st.end())
    {
        cout << *it << endl; // prints 11 if found
    }
    // rest all the functions are same as set
}

void explainMap()
{
    // map is a collection of key-value pairs in ascending order of keys, where each key is unique.
    // Keys and values can be of any data type, but all keys and all values must be of the same type respectively.
    map<int, string> mpp;
    mpp[1] = "abc";
    mpp[1] = "vik"; // overwrites the value of key 1
    mpp[2] = "bcd";
    mpp.emplace(3, "cat");
    mpp.insert({4, "Vaibhav"});
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl; // prints key and value pairs
    }
    cout << endl;

    auto it = mpp.find(4); // iterator pointing to key 4
    if (it != mpp.end())
    {
        cout << (*it).first << "->" << (*it).second << endl;
    }

    // lower bound returns an iterator that points to the first element that is >= key given
    auto it2 = mpp.lower_bound(2); // points to key 2
    // upper bound returns an iterator that points to the first element that is > key given
    auto it3 = mpp.upper_bound(2); // points to key 3
}

void explainUnorderedMap()
{
    unordered_map<int, string> mpp;
    mpp[1] = "abc";
    mpp[1] = "vik";
    mpp[2] = "bcd";
    mpp.emplace(3, "cat");
    mpp.insert({4, "Vaibhav"});
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl; // prints key and value pairs in random order.
    }
    cout << endl;

    auto it = mpp.find(4); // less time complexity as unordered_set O(1) and is almost constant until there are collisions inside the map.
    if (it != mpp.end())
    {
        cout << (*it).first << "->" << (*it).second << endl;
    }

    // no lower_bound or upper_bound functions in unordered_map as it does not maintain any order of keys.
}

void explainMultiMap()
{
    multimap<int, char> mpp;
    // multimap is similar to map, but it allows duplicate keys.
    mpp.insert({3, 'b'});
    mpp.insert({1, 'a'});
    mpp.insert({1, 'b'});
    mpp.insert({1, 'a'});
    mpp.insert({2, 'a'});
    mpp.insert({2, 'a'});
    mpp.insert({2, 'b'});

    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl; // prints key and value pairs in ascending order of keys only and not sorted based on values.
    }
    auto it = mpp.equal_range(2); // Returns a pair of iterators: first points to the first element with key 2, second points to the element after the last key 2.
    for (auto i = it.first; i != it.second; i++)
    {
        cout << (*i).first << "->" << (*i).second << endl; // prints all the values corresponding to key 2
    }
}

// FUNCTIONS and ALGORITHMS

void explainSort()
{
    int arr[5] = {6, 2, 1, 7, 8};
    sort(arr, arr + 5); // sorts the array in ascending order
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " "; // prints 1 2 6 7 8
    }
    cout << endl;

    int arr1[5] = {6, 2, 1, 7, 0};
    sort(arr1 + 1, arr1 + 4); // sorts elements at index 1, 2, and 3 (i.e., range [1, 4))
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " "; // prints 6 1 2 7 0
    }
    cout << endl;

    vector<int> vec = {5, 7, 1, 0, 1};
    sort(vec.begin() + 1, vec.begin() + 3); // sorts elements at index 1 and 2 (range [1, 3))
    for (auto it : vec)
    {
        cout << it << " "; // prints 5 1 7 0 1
    }
    cout << endl;
}

void explainAccumulate()
{
    int arr[5] = {6, 2, 1, 7, 8};
    cout << accumulate(arr, arr + 5, 0); // returns the sum of all elements in the array, starting from 0
    cout << endl;
    cout << accumulate(arr + 1, arr + 4, 10); // sums elements at index 1, 2, 3 (i.e., 2+1+7) and adds 10 → result is 20
}

void explainCount()
{
    int arr[5] = {6, 2, 1, 1, 0};
    int num = 1;
    cout << count(arr, arr + 5, num) << endl; // counts the occurrences of num (i.e. 1) in the array, which is 2

    // works with vectors as well
    vector<int> vec = {5, 5, 1, 5, 1};
    num = 5;
    cout << count(vec.begin(), vec.end(), num) << endl; // counts the occurrences of num (i.e. 5) in the vector, which is 3
}

void explainFind()
{
    int arr[5] = {6, 2, 1, 1, 0};
    auto it = find(arr, arr + 5, 1); // returns an iterator pointing to the first occurrence of 1 in the array
    if (it != arr + 5)
    {
        cout << *it << endl; // prints 1 if found
    }
    else
    {
        cout << "Not found" << endl; // prints if not found
    }

    // works with vectors as well
    vector<int> vec = {5, 5, 1, 5, 1};
    auto it1 = find(vec.begin(), vec.end(), 1); // returns an iterator pointing to the first occurrence of 1 in the vector
    if (it1 != vec.end())
    {
        cout << *it1 << endl; // prints 1 if found
    }
    else
    {
        cout << "Not found" << endl; // prints if not found
    }
}

void explainNextPermutation()
{
    string str = "abc";

    // Prints all permutations of "abc" in lexicographical order
    do
    {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
    cout << endl;

    // Resets str back to "abc" after full permutation cycle
    str = "abc";

    // Only permutes the first two characters: 'a' and 'b'
    do
    {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.begin() + 2));
    cout << endl;

    string str1 = "bca";

    // Starts from "bca" and prints remaining permutations in lexicographical order
    do
    {
        cout << str1 << endl;
    } while (next_permutation(str1.begin(), str1.end()));

    // works for vectors and arrays as well.
}

void explainPrevPermutation()
{
    string str = "cba";

    // Prints all permutations of "cba" in reverse lexicographical order
    do
    {
        cout << str << endl;
    } while (prev_permutation(str.begin(), str.end()));
    cout << endl;

    // Reset to "cba" to start fresh
    str = "cba";

    // Only permutes the first two characters: 'c' and 'b'
    do
    {
        cout << str << endl;
    } while (prev_permutation(str.begin(), str.begin() + 2));
    cout << endl;

    string str1 = "bca";

    // Starts from "bca" and prints permutations in reverse lexicographical order
    do
    {
        cout << str1 << endl;
    } while (prev_permutation(str1.begin(), str1.end()));

    // works for vectors and arrays as well.
}

void explainMaxAndMinElement()
{
    int arr[] = {7, 6, 5, 10, 9};
    auto it = max_element(arr, arr + 5); // returns an iterator pointing to the maximum element in the array
    cout << *it << endl;                 // prints 10

    // same for min_element
    auto it1 = min_element(arr, arr + 5); // returns an iterator pointing to the minimum element in the array
    cout << *it1 << endl;                 // prints 5
}

int main()
{
    explainMaxAndMinElement();
    return 0;
}