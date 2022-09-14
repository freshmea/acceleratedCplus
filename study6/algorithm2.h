#ifndef ACCELERATEDCPLUS_ALGORITHM2_H
#define ACCELERATEDCPLUS_ALGORITHM2_H
namespace aiot {

template<typename T>
bool equal(T b, T e, T d) {
    while (b != e) {
        if (*b++ != *d++)
            return false;
    }
    return true;
}

template<typename T, typename X>
T find(T b, T e, const X &d) {
    if (b == e || *b == d)
        return b;
    ++b;
    return aiot::find(b, e, d);
}

//template<typename T, typename F>
//T find_if(T b, T e, F f) {
//    if (f(*b))
//        return b;
//    ++b;
//    return aiot::find_if(b, e, f);
//}

template<typename T, typename F>
T find_if(T b, T e, bool (*func)(const F& val)) {
    while( b != e) {
        if (func(*b))
            return b;
        ++b;
    }
    return b;
}

template<typename I, typename O>
O copy(I b, I e, O d) {
    while (b != e)
        *d++ = *b++;
    return d;
}

template<typename T, typename D, typename F>
D transform(T b, T e, D d, F f) {
    while (b == e) {
        *d++ = f(*b);
        ++b;
    }
    return d;
}

template<typename T, typename T2>
T remove(T b, T e, const T2& val) {
    T result = b;
    while ( b != e){
        if(!(*b == val)){
            if(b != result)
                *result = *b;
            ++result;
        }
        ++b;
    }
    return result;
}

};
#endif //ACCELERATEDCPLUS_ALGORITHM2_H
