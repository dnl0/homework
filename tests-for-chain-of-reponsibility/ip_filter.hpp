#include <iostream>
#include <memory>
#include <vector>

class IPFilter {
public:
    virtual bool approve(const std::string& ipAddress) = 0;
    virtual void setNext(std::unique_ptr<IPFilter> nextFilter) = 0;
};

class BlacklistFilter : public IPFilter {
private:
    std::vector<std::string> blacklist_;
    std::unique_ptr<IPFilter> nextFilter_;

public:
    BlacklistFilter() {
        blacklist_.push_back("192.168.0.1");
        blacklist_.push_back("10.0.0.2");
    }

    bool approve(const std::string& ipAddress) override {
        for (const std::string& blacklistedIP : blacklist_) {
            if (ipAddress == blacklistedIP) {
                std::cout << "Denied: " << ipAddress << " is blacklisted." << std::endl;
                return false;
            }
        }
        if (nextFilter_) {
            return nextFilter_->approve(ipAddress);
        }
        return true;
    }

    void setNext(std::unique_ptr<IPFilter> nextFilter) override {
        nextFilter_ = std::move(nextFilter);
    }
};

class WhitelistFilter : public IPFilter {
private:
    std::vector<std::string> whitelist_;
    std::unique_ptr<IPFilter> nextFilter_;

public:
    WhitelistFilter() {
        whitelist_.push_back("192.168.0.2");
        whitelist_.push_back("10.0.0.3");
    }

    bool approve(const std::string& ipAddress) override {
        for (const std::string& whitelistedIP : whitelist_) {
            if (ipAddress == whitelistedIP) {
                std::cout << "Approved: " << ipAddress << " is whitelisted." << std::endl;
                return true;
            }
        }
        if (nextFilter_) {
            return nextFilter_->approve(ipAddress);
        }
        return false;
    }

    void setNext(std::unique_ptr<IPFilter> nextFilter) override {
        nextFilter_ = std::move(nextFilter);
    }
};
