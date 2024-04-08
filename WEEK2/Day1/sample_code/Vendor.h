#ifndef VENDOR_H
#define VENDOR_H

using DriverContainer = std::vector<Driver*>

class Vendor
{
private:
    std::string _vendorName{""};
    DriverContainer _drivers{};
public:
    void Vendor() override;
    
    ~Vendor() {}
};

#endif // VENDOR_H
