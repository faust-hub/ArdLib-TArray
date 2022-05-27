#include <Arduino.h>

namespace std {
	template <typename T>
	class initializer_list {
        protected:
            T *items;
            size_t TSize;
        public:
            constexpr initializer_list(): items(0), TSize(0) {}
            constexpr initializer_list(T* inItems, size_t needSize): items(inItems), TSize(needSize) {}
            constexpr size_t size() { return TSize; }
            constexpr T* begin() { return items; }
            constexpr T* end() { return begin() + size(); }
	};
}

template <typename T>
class TArray {
    #define ENUMERATION for (size_t ind = 0; ind < TSize; ind++)
    #define LAST TSize - 1

    private:
        using tCbItem = void (*)(T);
        using tCbItemResult = T (*)(T);
        using tCbItemIndex = void (*)(T, uint8_t);
        using tCbItemIndexResult = T (*)(T, uint8_t);

        T* items;
        size_t TSize;

    public:
        TArray(size_t needSize = 0, T val = T()) {
            items = new T[TSize = needSize];
            ENUMERATION items[ind] = val;
        }

        TArray(const std::initializer_list<T> &list): TArray(list.size()) {
            size_t ind = 0;
            for (auto& item:list) items[ind++] = item;
        }

        T& operator[](size_t ind) {
            return items[constrain(ind, 0, LAST)];
        }

        uint8_t length() {
            return TSize;
        }

        template <typename... Args>
        void push(T val, Args... inValues) {
            push(val);
            push(inValues...);
        }

        void push(T val) {
            items = (T*) realloc(items, ++TSize * sizeof(T));
            items[LAST] = val;
        }

        T pop() {
            T val = items[LAST];
            items = (T*) realloc(items, --TSize * sizeof(T));
            return val;
        }

        void forEach(tCbItem callback) {
            ENUMERATION callback(items[ind]);
        }

        void forEach(tCbItemIndex callback) {
            ENUMERATION callback(items[ind], ind);
        }

        void modify(tCbItemResult callback) {
            ENUMERATION items[ind] = callback(items[ind]);
        }

        void modify(tCbItemIndexResult callback) {
            ENUMERATION items[ind] = callback(items[ind], ind);
        }

        template <typename T2>
        TArray <T2> map(T2 (*callback)(T)) {
            TArray <T2> res(TSize);
            ENUMERATION res[ind] = callback(items[ind]);
            return res;
        }

        template <typename T2>
        TArray <T2> map(T2 (*callback)(T, uint8_t)) {
            TArray <T2> res(TSize);
            ENUMERATION res[ind] = callback(items[ind], ind);
            return res;
        }
};
