#include <gtest/gtest.h>
#include "ip_filter.hpp"

class IPFilterTest : public ::testing::Test {
protected:
  std::unique_ptr<IPFilter> filter;
};

TEST_F(IPFilterTest, BlacklistedIPAddress) {
  filter = std::make_unique<BlacklistFilter>();

  std::string ipAddress = "192.168.0.1";
  bool result = filter->approve(ipAddress);
  EXPECT_FALSE(result);
}

TEST_F(IPFilterTest, WhitelistedIPAddress) {
  filter = std::make_unique<WhitelistFilter>();

  std::string ipAddress = "192.168.0.2";
  bool result = filter->approve(ipAddress);
  EXPECT_TRUE(result);
}

TEST_F(IPFilterTest, NonBlacklistedNonWhitelistedIPAddress) {
  filter = std::make_unique<BlacklistFilter>();

  std::string ipAddress = "192.168.0.3";
  bool result = filter->approve(ipAddress);
  EXPECT_TRUE(result);
}

TEST_F(IPFilterTest, NonWhitelistedNonBlacklistedIPAddress) {
  filter = std::make_unique<WhitelistFilter>();

  std::string ipAddress = "192.168.0.3";
  bool result = filter->approve(ipAddress);
  EXPECT_FALSE(result);
}
