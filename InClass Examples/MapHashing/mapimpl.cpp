////* File: mapimpl.cpp
//#include<iostream>
//using namespace std;
//#ifdef _map_h
//template <typename ValueType>
//
//Map<ValueType>::Map() {
//	capacity = INITIAL_CAPACITY;
//	array = new keyValuePairT[capacity];
//	count = 0;
//}
//
//template <typename ValueType>
//Map<ValueType>::~Map() {
//	delete[] array;
//}
//
//template <typename ValueType>
//int Map<ValueType>::size() {
//	return count;
//}
//template <typename ValueType>
//bool Map<ValueType>::isEmpty() {
//	return (count == 0);
//}
//template <typename ValueType>
//void Map<ValueType>::clear() {
//	count = 0;
//}
//
//template <typename ValueType>
//void Map<ValueType>::put(string key, ValueType value) {
//	int index = findKey(key);
//	if (index == -1) {
//		if (count == capacity) expandCapacity();
//		index = count++;
//		array[index].key = key;
//	}
//	array[index].value = value;
//}
//template <typename ValueType>
//ValueType Map<ValueType>::get(string key) {
//	int index = findKey(key);
//	if (index == -1) {
//		//Error("Attempt to get value for key that is not in the map.");
//	}
//	return array[index].value;
//}
//
//template <typename ValueType>
//bool Map<ValueType>::containsKey(string key) {
//	return (findKey(key) != -1);
//}
//template <typename ValueType>
//void Map<ValueType>::remove(string key) {
//	int index = findKey(key);
//	if (index != -1) {
//		array[index] = array[--count];
//	}
//}
//template <typename ValueType>
//int Map<ValueType>::findKey(string key) {
//	for (int i = 0; i < count; i++) {
//		if (array[i].key == key) return i;
//	}
//	return -1;
//}
//
//template <typename ValueType>
//void Map<ValueType>::expandCapacity() {
//	int count = size();
//	capacity *= 2;
//	keyValuePairT* oldArray = array;
//	array = new keyValuePairT[capacity];
//	for (int i = 0; i < count; i++) {
//		array[i] = oldArray[i];
//	}
//	delete[] oldArray;
//}
//#endif
//
