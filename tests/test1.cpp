#include "gtest/gtest.h"
#include "../banking/Account.h"

TEST(Acc, testall)
{
  Account acc(12312, 450);
  
  //check get
  EXPECT_EQ(acc.GetBalance(), 450);
  
  //check lock/unlock
  EXPECT_THROW(acc.ChangeBalance(50), std::runtime_error);
  acc.Lock(); 
  EXPECT_NO_THROW(acc.ChangeBalance(50));
  EXPECT_EQ(acc.GetBalance(), 500);
  EXPECT_THROW(acc.Lock(), std::runtime_error);
  acc.Unlock();
  EXPECT_THROW(acc.ChangeBalance(50), std::runtime_error);
}
  
