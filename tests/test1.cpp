#include "gtest/gtest.h"
#include "../banking/Account.h"

TEST(Acc, testall)
{
  Account acc(12312, 370);
  
  //check get
  EXPECT_EQ(acc.GetBalance(), 370);
  
  //check lock/unlock
  EXPECT_THROW(acc.ChangeBalance(70), std::runtime_error);
  acc.Lock(); 
  EXPECT_NO_THROW(acc.ChangeBalance(30));
  EXPECT_EQ(acc.GetBalance(), 400);
  EXPECT_THROW(acc.Lock(), std::runtime_error);
  acc.Unlock();
  EXPECT_THROW(acc.ChangeBalance(37), std::runtime_error);
}
  
