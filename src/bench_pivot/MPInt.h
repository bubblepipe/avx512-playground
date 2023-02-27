// #include <cstdint>
// class MPInt {
// private:
//   union {
//     int64_t valSmall;
//     int64_t valLarge;
//   };
//   unsigned holdsLarge;

  
//   inline void initSmall(int64_t o) {
//     // if (LLVM_UNLIKELY(isLarge()))
//     //   valLarge.detail::SlowMPInt::~SlowMPInt();
//     valSmall = o;
//     holdsLarge = false;
//   }
// //   inline void initLarge(const detail::SlowMPInt &o) { }

// //   inline explicit MPInt(const detail::SlowMPInt &val)
// //       : valLarge(val), holdsLarge(true) {}
//   inline bool isSmall() const { return !holdsLarge; }
//   inline bool isLarge() const { return holdsLarge; }
//   /// Get the stored value. For getSmall/Large,
//   /// the stored value should be small/large.
//   inline int64_t getSmall() const {
//     return valSmall;
//   }
//   inline int64_t &getSmall() {
//     return valSmall;
//   }
// //   inline const detail::SlowMPInt &getLarge() const {
// //   inline detail::SlowMPInt &getLarge() {
    
// //   explicit operator detail::SlowMPInt() const {

// public:


//   inline explicit MPInt(int64_t val)
//       : valSmall(val), holdsLarge(false) {}
//   inline MPInt() : MPInt(0) {}
//   inline ~MPInt() { }
//   inline MPInt(const MPInt &o)
//       : valSmall(o.valSmall), holdsLarge(false) { }
//   inline MPInt &operator=(const MPInt &o) {
//       initSmall(o.valSmall);
//       return *this;
//   }
//   inline MPInt &operator=(int x) {
//     initSmall(x);
//     return *this;
//   }
//   inline explicit operator int64_t() const {
//     return getSmall();
//   }

//   bool operator==(const MPInt &o) const;
//   bool operator!=(const MPInt &o) const;
//   bool operator>(const MPInt &o) const;
//   bool operator<(const MPInt &o) const;
//   bool operator<=(const MPInt &o) const;
//   bool operator>=(const MPInt &o) const;
//   MPInt operator+(const MPInt &o) const;
//   MPInt operator-(const MPInt &o) const;
//   MPInt operator*(const MPInt &o) const;
//   MPInt operator/(const MPInt &o) const;
//   MPInt operator%(const MPInt &o) const;
//   MPInt &operator+=(const MPInt &o);
//   MPInt &operator-=(const MPInt &o);
//   MPInt &operator*=(const MPInt &o);
//   MPInt &operator/=(const MPInt &o);
//   MPInt &operator%=(const MPInt &o);
//   MPInt operator-() const;
//   MPInt &operator++();
//   MPInt &operator--();
  
//   friend MPInt &operator+=(MPInt &a, int64_t b);
//   friend MPInt &operator-=(MPInt &a, int64_t b);
//   friend MPInt &operator*=(MPInt &a, int64_t b);
//   friend MPInt &operator/=(MPInt &a, int64_t b);
//   friend MPInt &operator%=(MPInt &a, int64_t b);

//   friend bool operator==(const MPInt &a, int64_t b);
//   friend bool operator!=(const MPInt &a, int64_t b);
//   friend bool operator>(const MPInt &a, int64_t b);
//   friend bool operator<(const MPInt &a, int64_t b);
//   friend bool operator<=(const MPInt &a, int64_t b);
//   friend bool operator>=(const MPInt &a, int64_t b);
//   friend MPInt operator+(const MPInt &a, int64_t b);
//   friend MPInt operator-(const MPInt &a, int64_t b);
//   friend MPInt operator*(const MPInt &a, int64_t b);
//   friend MPInt operator/(const MPInt &a, int64_t b);
//   friend MPInt operator%(const MPInt &a, int64_t b);

//   friend bool operator==(int64_t a, const MPInt &b);
//   friend bool operator!=(int64_t a, const MPInt &b);
//   friend bool operator>(int64_t a, const MPInt &b);
//   friend bool operator<(int64_t a, const MPInt &b);
//   friend bool operator<=(int64_t a, const MPInt &b);
//   friend bool operator>=(int64_t a, const MPInt &b);
//   friend MPInt operator+(int64_t a, const MPInt &b);
//   friend MPInt operator-(int64_t a, const MPInt &b);
//   friend MPInt operator*(int64_t a, const MPInt &b);
//   friend MPInt operator/(int64_t a, const MPInt &b);
//   friend MPInt operator%(int64_t a, const MPInt &b);
// };