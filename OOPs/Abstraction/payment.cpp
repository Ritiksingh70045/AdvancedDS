#include <bits/stdc++.h>
using namespace std;

class Payment
{
public:
  virtual void pay(int amount) = 0;

protected:
  void validate()
  {
    cout << "Validated the payment\n";
  }

public:
  virtual ~Payment() {}
};

class CreditCard : public Payment
{
public:
  void pay(int amount) override
  {
    validate();
    cout << amount << " credited successfully!!!\n";
  }
};

class UPI : public Payment
{
public:
  void pay(int amount) override
  {
    validate();
    cout << amount << " paid via UPI\n";
  }
};

int main()
{
  Payment *p1 = new CreditCard();
  Payment *p2 = new UPI();

  p1->pay(1000);
  p2->pay(500);

  delete p1;
  delete p2;
}
