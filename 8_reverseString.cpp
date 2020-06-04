// std::move is used to indicate that an object t may be "moved from", 
// i.e. allowing the efficient transfer of resources from t to another object.

template <typename T>
void my_swap(T& a, T& b)
{
    auto tmp = move(a);
    a = move(b);
    b = move(tmp);
}


class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, j = (int)s.size()-1; i < j; ++i, --j)
            my_swap(s[i], s[j]);
    }
};
