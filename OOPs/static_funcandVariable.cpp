#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class DatabaseConnection
{
private:
  int connectionId;
  bool active;

  // Shared among all objects
  static int nextConnectionId;
  static int activeConnections;
  static unordered_map<int, string> connectionLogs;

public:
  DatabaseConnection()
  {
    connectionId = ++nextConnectionId;
    active = true;
    activeConnections++;

    connectionLogs[connectionId] = "Connection Established";
  }

  ~DatabaseConnection()
  {
    if (active)
    {
      closeConnection();
    }
  }

  void closeConnection()
  {
    if (!active)
      return;

    active = false;
    activeConnections--;
    connectionLogs[connectionId] = "Connection Closed";
  }

  int getId() const
  {
    return connectionId;
  }

  // Static function manipulating static variables
  static void printStatistics()
  {
    cout << "\n----- Server Statistics -----\n";
    cout << "Total Connections Created : "
         << nextConnectionId << endl;

    cout << "Currently Active          : "
         << activeConnections << endl;

    cout << "\nConnection Logs\n";

    for (auto &entry : connectionLogs)
    {
      cout << "Connection "
           << entry.first
           << " -> "
           << entry.second
           << endl;
    }
  }
};

// Static member definitions
int DatabaseConnection::nextConnectionId = 0;
int DatabaseConnection::activeConnections = 0;
unordered_map<int, string> DatabaseConnection::connectionLogs;

int main()
{

  DatabaseConnection db1;
  DatabaseConnection db2;
  DatabaseConnection db3;

  db2.closeConnection();

  DatabaseConnection::printStatistics();
}