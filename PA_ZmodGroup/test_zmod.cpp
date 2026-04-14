#include <gtest/gtest.h>

#include "zmod/ZModGroup.hpp"

#include <mathgroup/direct_sum.hpp>

using zmod::ZModElement;

TEST(ZModElement, NormalizesIntoRange) {
  EXPECT_EQ((ZModElement<5>(7).value()), 2);
  EXPECT_EQ((ZModElement<5>(-1).value()), 4);
}

TEST(ZModElement, Addition) {
  ZModElement<5> a{7}; // 2
  ZModElement<5> b{3}; // 3

  EXPECT_EQ((a + b).value(), 0);
  EXPECT_EQ(a.add(b).value(), 0);
}

TEST(ZModElement, CompoundAssignment) {
  ZModElement<5> a{2};
  a += ZModElement<5>{4};
  EXPECT_EQ(a.value(), 1);
}

TEST(ZModElement, EqualsMethodMatchesOperatorEq) {
  ZModElement<5> a{7};  // 2
  ZModElement<5> b{2};
  ZModElement<5> c{3};

  EXPECT_TRUE(a.equals(b));
  EXPECT_FALSE(a.equals(c));
}

TEST(ZModGroup, CanBuildFromModulusOnly) {
  const auto g = zmod::makeZModGroup<5>();

  EXPECT_EQ(g.order(), 5u);
  EXPECT_EQ(g.identity().value(), 0);

  // 2 + 3 = 0 (mod 5)
  EXPECT_EQ(g.operate(2, 3).value(), 0);

  // inverse of 2 is 3 in additive Z5
  EXPECT_EQ(g.inverse(2).value(), 3);
}

TEST(ZModGroup, DirectSumZ2Z3IsIsomorphicToZ6) {
  const auto z2 = zmod::makeZModGroup<2>();
  const auto z3 = zmod::makeZModGroup<3>();
  const auto z6 = zmod::makeZModGroup<6>();

  const auto z2xz3 = z2 + z3;

  // For additive finite abelian groups: Z2 ⊕ Z3 ≅ Z6.
  // MathGroup defines operator== as "isomorphic".
  EXPECT_TRUE(z2xz3 == z6);
}






