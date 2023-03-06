#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <limits>

class MPInt {
private:
  union {
    int64_t valSmall;
    int64_t valLarge;
  };
  unsigned holdsLarge;

  inline void initSmall(int64_t o) {
    // if (LLVM_UNLIKELY(isLarge()))
    //   valLarge.detail::SlowMPInt::~SlowMPInt();
    valSmall = o;
    holdsLarge = false;
  }
//   inline void initLarge(const detail::SlowMPInt &o) {
//     if (LLVM_LIKELY(isSmall())) {
//       // The data in memory could be in an arbitrary state, not necessarily
//       // corresponding to any valid state of valLarge; we cannot call any member
//       // functions, e.g. the assignment operator on it, as they may access the
//       // invalid internal state. We instead construct a new object using
//       // placement new.
//       new (&valLarge) detail::SlowMPInt(o);
//     } else {
//       // In this case, we need to use the assignment operator, because if we use
//       // placement-new as above we would lose track of allocated memory
//       // and leak it.
//       valLarge = o;
//     }
//     holdsLarge = true;
//   }

//   inline explicit MPInt(const detail::SlowMPInt &val)
//       : valLarge(val), holdsLarge(true) {}
  inline bool isSmall() const { return !holdsLarge; }
  inline bool isLarge() const { return holdsLarge; }
  /// Get the stored value. For getSmall/Large,
  /// the stored value should be small/large.
  inline int64_t getSmall() const {
    return valSmall;
  }
  inline int64_t &getSmall() {
    return valSmall;
  }
  inline const int64_t &getLarge() const {
    return valLarge;
  }
  inline int64_t &getLarge() {
    return valLarge;
  }
//   explicit operator detail::SlowMPInt() const {
    // if (isSmall())
    //   return detail::SlowMPInt(getSmall());
    // return getLarge();
//   }

public:
  inline explicit MPInt(int64_t val)
      : valSmall(val), holdsLarge(false) {}
  inline MPInt() : MPInt(0) {}
  inline ~MPInt() {
    // if (LLVM_UNLIKELY(isLarge()))
    //   valLarge.detail::SlowMPInt::~SlowMPInt();
  }
  inline MPInt(const MPInt &o)
      : valSmall(o.valSmall), holdsLarge(false) {
    // if (LLVM_UNLIKELY(o.isLarge()))
    //   initLarge(o.valLarge);
  }
  inline MPInt &operator=(const MPInt &o) {
    // if (LLVM_LIKELY(o.isSmall())) {
      initSmall(o.valSmall);
      return *this;
    // }
    // initLarge(o.valLarge);
    // return *this;
  }
  inline MPInt &operator=(int x) {
    initSmall(x);
    return *this;
  }
  inline explicit operator int64_t() const {
    if (isSmall())
      return getSmall();
    return static_cast<int64_t>(getLarge());
  }
  inline explicit operator int32_t() const {
    if (isSmall())
      return getSmall();
    return static_cast<int32_t>(getLarge());
  }
//   bool operator==(const MPInt &o) const;
//   bool operator!=(const MPInt &o) const;
//   bool operator>(const MPInt &o) const;
//   bool operator<(const MPInt &o) const;
//   bool operator<=(const MPInt &o) const;
//   bool operator>=(const MPInt &o) const;
  MPInt operator+(const MPInt &o) const;
//   MPInt operator-(const MPInt &o) const;
  MPInt operator*(const MPInt &o) const;
  MPInt operator/(const MPInt &o) const;
//   MPInt operator%(const MPInt &o) const;
//   MPInt &operator+=(const MPInt &o);
//   MPInt &operator-=(const MPInt &o);
  MPInt &operator*=(const MPInt &o);
//   MPInt &operator/=(const MPInt &o);
//   MPInt &operator%=(const MPInt &o);
  MPInt operator-() const;
//   MPInt &operator++();
//   MPInt &operator--();

  // Divide by a number that is known to be positive.
  // This is slightly more efficient because it saves an overflow check.
//   MPInt divByPositive(const MPInt &o) const;
//   MPInt &divByPositiveInPlace(const MPInt &o);

//   friend MPInt abs(const MPInt &x);
// //   friend MPInt gcdRange(ArrayRef<MPInt> range);
//   friend MPInt ceilDiv(const MPInt &lhs, const MPInt &rhs);
//   friend MPInt floorDiv(const MPInt &lhs, const MPInt &rhs);
//   // The operands must be non-negative for gcd.
//   friend MPInt gcd(const MPInt &a, const MPInt &b);
//   friend MPInt lcm(const MPInt &a, const MPInt &b);
//   friend MPInt mod(const MPInt &lhs, const MPInt &rhs);

//   llvm::raw_ostream &print(llvm::raw_ostream &os) const;
//   void dump() const;

  /// ---------------------------------------------------------------------------
  /// Convenience operator overloads for int64_t.
  /// ---------------------------------------------------------------------------
//   friend MPInt &operator+=(MPInt &a, int64_t b);
//   friend MPInt &operator-=(MPInt &a, int64_t b);
//   friend MPInt &operator*=(MPInt &a, int64_t b);
//   friend MPInt &operator/=(MPInt &a, int64_t b);
//   friend MPInt &operator%=(MPInt &a, int64_t b);

  friend bool operator==(const MPInt &a, int64_t b);
//   friend bool operator!=(const MPInt &a, int64_t b);
//   friend bool operator>(const MPInt &a, int64_t b);
  friend bool operator<(const MPInt &a, int64_t b);
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

//   friend llvm::hash_code hash_value(const MPInt &x); // NOLINT

    // operator float() const {
    //   printf("unexpected cast MPInt to float\n");
    //   exit(0);
    // }
};

inline bool addOverflow(int64_t x, int64_t y,
                                              int64_t &result) {
  return __builtin_add_overflow(x, y, &result);
}
inline MPInt MPInt::operator+(const MPInt &o) const {
    MPInt result;
    bool overflow = addOverflow(getSmall(), o.getSmall(), result.getSmall());
    if (!overflow)
      return result;
    return (MPInt)0;
}

inline bool mulOverflow(int64_t x, int64_t y,
                                              int64_t &result) {
  return __builtin_mul_overflow(x, y, &result);
}

inline MPInt MPInt::operator*(const MPInt &o) const {
    MPInt result;
    bool overflow = mulOverflow(getSmall(), o.getSmall(), result.getSmall());
    if (!overflow)
      return result;
    return (MPInt)0;
}

inline bool divWouldOverflow(int64_t x, int64_t y) {
  return x == std::numeric_limits<int64_t>::min() && y == -1;
}
inline MPInt MPInt::operator/(const MPInt &o) const {
    // Division overflows only occur when negating the minimal possible value.
    if (divWouldOverflow(getSmall(), o.getSmall()))
      return -*this;
    return MPInt(getSmall() / o.getSmall());
}


inline MPInt &MPInt::operator*=(const MPInt &o) {
    int64_t result = getSmall();
    bool overflow = mulOverflow(getSmall(), o.getSmall(), result);
    getSmall() = result;

    if (!overflow)
      return *this;
    return *this = MPInt(0);
}


inline MPInt MPInt::operator-() const {
    if (getSmall() != std::numeric_limits<int64_t>::min())
      return MPInt(-getSmall());
    return MPInt(0);
}

inline bool operator==(const MPInt &a, int64_t b) {
    return a.getSmall() == b;
}  

inline bool operator<(const MPInt &a, int64_t b) {
    return a.getSmall() < b;
}