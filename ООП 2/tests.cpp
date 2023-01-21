#include "gtest/gtest.h"
#include "hashtag.h"

TEST(HashtagTest, HashtagCreate)
{
	EXPECT_EQ(Turn_Hash("Save me, please"), "#SaveMePlease");
	EXPECT_EQ(Turn_Hash("                Stop again"), "#StopAgain");
	EXPECT_EQ(Turn_Hash("Do not stopping dream                    "), "#DoNotStoppingDream");
	EXPECT_EQ(Turn_Hash("your not              too weak"), "#YourNotTooWeak");
}

TEST(ExeptionTest, EmptyString)
{
	ASSERT_THROW(Turn_Hash(""), const char*);
	ASSERT_THROW(Turn_Hash("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"), const char*);
}