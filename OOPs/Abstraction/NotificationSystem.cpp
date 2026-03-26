#include <bits/stdc++.h>
using namespace std;

class Notification
{
public:
  virtual void send(const string &msg) = 0;

protected:
  void logNotification(const string &msg)
  {
    cout << "Log: " << msg << endl;
  }

public:
  virtual ~Notification() {}
};

class Email : public Notification
{
public:
  void send(const string &msg) override
  {
    cout << "Sending Email: " << msg << endl;
    logNotification(msg);
  }
};

class SMS : public Notification
{
public:
  void send(const string &msg) override
  {
    cout << "Sending SMS: " << msg << endl;
    logNotification(msg);
  }
};

class Push : public Notification
{
public:
  void send(const string &msg) override
  {
    cout << "Sending Push Notification: " << msg << endl;
    logNotification(msg);
  }
};

int main()
{
  Notification *n;

  n = new Email();
  n->send("Hello via Email");
  delete n;

  n = new SMS();
  n->send("Hello via SMS");
  delete n;

  n = new Push();
  n->send("Hello via Push");
  delete n;
}




//* A virtual destructor ensures that when you delete an object using a base class pointer, the derived class destructor is also called. Without virtual, only the base destructor runs, which can cause resource leaks if the derived class has allocated memory or resources. So, making the destructor virtual guarantees proper cleanup in polymorphic use cases.