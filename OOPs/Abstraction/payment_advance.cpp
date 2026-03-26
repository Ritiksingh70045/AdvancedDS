#include <bits/stdc++.h>
using namespace std;

class PaymentStrategy
{
public:
  virtual void pay(int amount) = 0;
  virtual ~PaymentStrategy() {}
};

class CreditCard : public PaymentStrategy
{
public:
  void pay(int amount) override
  {
    cout << "Paid " << amount << " using Credit Card\n";
  }
};

class UPI : public PaymentStrategy
{
public:
  void pay(int amount) override
  {
    cout << "Paid " << amount << " using UPI\n";
  }
};

class Wallet : public PaymentStrategy
{
public:
  void pay(int amount) override
  {
    cout << "Paid " << amount << " using Wallet\n";
  }
};

class ShoppingCart
{
private:
  PaymentStrategy *strategy; //  PaymentStrategy is an abstract class . You cannot create its object

public:
  ShoppingCart()
  {
    strategy = nullptr;
  }

  void setPaymentStrategy(PaymentStrategy *s)
  {
    strategy = s;
  }

  void checkout(int amount)
  {
    if (!strategy)
    {
      cout << "No payment method selected\n";
      return;
    }
    strategy->pay(amount);
  }
};

int main()
{
  ShoppingCart cart;

  cart.setPaymentStrategy(new CreditCard());
  cart.checkout(1000);

  cart.setPaymentStrategy(new UPI());
  cart.checkout(500);
}