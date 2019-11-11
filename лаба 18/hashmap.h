#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <cstdlib>

template <class T>
class hashmap {
private:
	std::vector< std::list <std::pair<const std::string, T>> > hmap;
	int size;

public:
	hashmap(int Size);
	~hashmap();
	std::pair<T, bool> find(const std::string& key);
	void erase(const std::string& key);
	void insert(const std::string& key, T value);
	template <class T> friend std::ostream& operator<<(std::ostream& out, const hashmap<T>& o);
};

template <class T>
hashmap<T>::hashmap(int Size) {
	size = Size;
	hmap.resize(size);
}


template <class T>
hashmap<T>::~hashmap() {
	hmap.clear();
}

template<class T>
std::pair<T, bool> hashmap<T>::find(const std::string& key) {
	std::pair<T, bool> FindElement(0, false);
	unsigned hash = key.length() % size;
		for (std::list < std::pair < const std::string, T>>::iterator it = hmap[hash].begin(); it != hmap[hash].end(); ++it)
		{
			if (key == (it->first)) {
				FindElement.first = it->second;
				FindElement.second=true;
				break;
			}
		}
		return FindElement;
}

template <class T>
void hashmap<T>::erase(const std::string& key) {
	size_t hash = key.length() % size;
		for (std::list<std::pair< const std::string, T>>::iterator it = hmap[hash].begin(); it != hmap[hash].end(); ++it)
		{
			if (key == it->first)
			{
				hmap[key.length() % size].remove(*(it));
				return;
			}
		}
			std::string WrongKey1 = "This element -> (";
			std::string WrongKey2 = ") is not found";
			std::string WrongKey = WrongKey1 + key + WrongKey2;
			
			throw std::runtime_error(WrongKey);
}

template <class T>
void hashmap<T>::insert(const std::string& key, T value) {
	size_t hash = key.length() % size;
	for (std::list < std::pair< const std::string, T>>::iterator it = hmap[hash].begin(); it != hmap[hash].end(); ++it)
	{
		if (key == (it->first)) {
			it->second = value;
			return;
		}
	}
	std::pair < const std::string, T> InsertElement(key, value);
	hmap[hash].push_front(InsertElement);
}

template <class T>
std::ostream& operator<<(std::ostream& out, const hashmap<T>& o) {
	{
		for (size_t i = 0; i < o.hmap.size(); i++)
		{
			out<<"Hash->" << "[" << i << "]:  ";
			for (std::list<std::pair<const std::string, T>>::const_iterator it = o.hmap[i].begin(); it != o.hmap[i].end(); it++)
			{
				out << it->first << ' ' << it->second << ' ';
			}
			out << '\n';
		}
		return out;
	}
}