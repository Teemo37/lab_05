#include "../banking/Account.h"
#include "../banking/Transaction.h"
#include "gtest/gtest.h"

TEST(Transaction, Banking)
{
  const int sum1 = 500, sum2 = 300, fee = 100;

  Account a1(123, sum1), a2(456, sum2);
  Transaction test;
  
  //set & get
  EXPECT_EQ(test.fee(), 1);
  test.set_fee(fee);
  EXPECT_EQ(test.fee(), fee);
	
  //check exceptions
  EXPECT_THROW(test.Make(a1, a1, 100), std::logic_error);
  EXPECT_THROW(test.Make(a1, a2, -10), std::invalid_argument);
  EXPECT_THROW(test.Make(a1, a2, 10), std::logic_error);
  EXPECT_EQ(test.Make(a1, a2, test.fee()*2-1), false);
  a2.Lock();
  EXPECT_THROW(test.Make(a1, a2, 200), std::runtime_error);
  a2.Unlock();
	
  //check cancelled transaction	
  EXPECT_EQ(test.Make(a1, a2, sum1-fee), false);
  EXPECT_EQ(a2.GetBalance(), sum2);	
  EXPECT_EQ(a1.GetBalance(), sum1);

  //check successful transaction	
  EXPECT_EQ(test.Make(a1, a2, 300), true);
  EXPECT_EQ(a2.GetBalance(), sum2+300);	
  EXPECT_EQ(a1.GetBalance(), sum1-300-fee);
}
