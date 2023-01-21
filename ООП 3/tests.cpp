#include "gtest/gtest.h"
#include "base64.h"
using namespace std;

TEST(num, step) {
	EXPECT_EQ(Bin_turn(32, 7), "0100000");
}

TEST(str, str_enc_bin) {
	EXPECT_EQ(Encode_make_bin("abc"), "011000010110001001100011");
}

TEST(bin_str, ch) {
	EXPECT_EQ(convert("01100001"), 'a');
}

TEST(str, str_dec_bin) {
	EXPECT_EQ(Decode_make_bin("YWJj"), "011000010110001001100011");
}

TEST(str, encode_str) {
	EXPECT_EQ(encode("abc"), "YWJj");
}

TEST(str, decode_str) {
	EXPECT_EQ(decode("MTIz"), "123");
}