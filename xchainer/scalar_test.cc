#include "xchainer/scalar.h"

#include <gtest/gtest.h>

namespace xchainer {
namespace {

TEST(ScalarTest, Dtype) {
    ASSERT_EQ(Scalar(true).dtype(), Dtype::kBool);
    ASSERT_EQ(Scalar(false).dtype(), Dtype::kBool);
    ASSERT_EQ(Scalar(int8_t(1)).dtype(), Dtype::kInt8);
    ASSERT_EQ(Scalar(int16_t(2)).dtype(), Dtype::kInt16);
    ASSERT_EQ(Scalar(int32_t(3)).dtype(), Dtype::kInt32);
    ASSERT_EQ(Scalar(int64_t(4)).dtype(), Dtype::kInt64);
    ASSERT_EQ(Scalar(uint8_t(5)).dtype(), Dtype::kUInt8);
    ASSERT_EQ(Scalar(6.7f).dtype(), Dtype::kFloat32);
    ASSERT_EQ(Scalar(8.9).dtype(), Dtype::kFloat64);
}

TEST(ScalarTest, Cast) {
    ASSERT_TRUE(bool(Scalar(true)));
    ASSERT_TRUE(bool(Scalar(1)));
    ASSERT_FALSE(bool(Scalar(false)));
    ASSERT_FALSE(bool(Scalar(0)));
    ASSERT_EQ(int8_t(Scalar(1)), 1);
    ASSERT_EQ(int16_t(Scalar(2)), 2);
    ASSERT_EQ(int32_t(Scalar(3)), 3);
    ASSERT_EQ(int64_t(Scalar(4)), 4);
    ASSERT_EQ(uint8_t(Scalar(5)), 5);
    ASSERT_FLOAT_EQ(float(Scalar(6)), 6.0f);
    ASSERT_FLOAT_EQ(float(Scalar(6.7)), 6.7f);
    ASSERT_DOUBLE_EQ(double(Scalar(8)), 8.0);
    ASSERT_DOUBLE_EQ(double(Scalar(8.9)), 8.9);
}

TEST(DtypeTest, UnaryOps) {
    ASSERT_THROW(-Scalar(true), DtypeError);
    ASSERT_THROW(-Scalar(false), DtypeError);
    ASSERT_EQ(int8_t(-Scalar(1)), -1);
    ASSERT_EQ(int16_t(-Scalar(2)), -2);
    ASSERT_EQ(int32_t(-Scalar(3)), -3);
    ASSERT_EQ(int64_t(-Scalar(4)), -4);
    ASSERT_EQ(uint8_t(-Scalar(5)), uint8_t(-5));
    ASSERT_FLOAT_EQ(float(-Scalar(6)), -6.0f);
    ASSERT_FLOAT_EQ(float(-Scalar(6.7)), -6.7f);
    ASSERT_DOUBLE_EQ(double(-Scalar(8)), -8.0);
    ASSERT_DOUBLE_EQ(double(-Scalar(8.9)), -8.9);

    ASSERT_EQ(int8_t(+Scalar(1)), 1);
    ASSERT_EQ(int16_t(+Scalar(2)), 2);
    ASSERT_EQ(int32_t(+Scalar(3)), 3);
    ASSERT_EQ(int64_t(+Scalar(4)), 4);
    ASSERT_EQ(uint8_t(+Scalar(5)), 5);
    ASSERT_EQ(float(+Scalar(5)), 5);
    ASSERT_FLOAT_EQ(float(+Scalar(6)), 6.0f);
    ASSERT_FLOAT_EQ(float(+Scalar(6.7)), 6.7f);
    ASSERT_DOUBLE_EQ(double(+Scalar(8)), 8.0);
    ASSERT_DOUBLE_EQ(double(+Scalar(8.9)), 8.9);
}

TEST(ScalarTest, ToString) {
    ASSERT_STREQ(Scalar(true).ToString().c_str(), "True");
    ASSERT_STREQ(Scalar(false).ToString().c_str(), "False");
    ASSERT_STREQ(Scalar(int8_t(1)).ToString().c_str(), std::to_string(int8_t(1)).c_str());
    ASSERT_STREQ(Scalar(int16_t(2)).ToString().c_str(), std::to_string(int16_t(2)).c_str());
    ASSERT_STREQ(Scalar(int32_t(3)).ToString().c_str(), std::to_string(int32_t(3)).c_str());
    ASSERT_STREQ(Scalar(int64_t(4)).ToString().c_str(), std::to_string(int64_t(4)).c_str());
    ASSERT_STREQ(Scalar(uint8_t(5)).ToString().c_str(), std::to_string(uint8_t(5)).c_str());
}

}  // namespace
}  // namespace xchainer
