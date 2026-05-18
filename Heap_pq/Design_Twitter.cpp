class Twitter
{
public:
  unordered_map<int, unordered_set<int>> following;
  unordered_map<int, vector<pair<int, int>>> tweets;
  int time;
  Twitter() { time = 0; }

  void postTweet(int userId, int tweetId)
  {
    tweets[userId].push_back({time++, tweetId});
  }

  vector<int> getNewsFeed(int userId)
  {
    priority_queue<pair<int, int>> pq;
    following[userId].insert(userId);
    for (auto followee : following[userId])
    {
      auto &userTweets = tweets[followee];
      int size = userTweets.size();

      for (int i = max(0, size - 10); i < size; i++)
      {
        pq.push(userTweets[i]);
      }
    }
    vector<int> res;
    int count = 10;

    while (!pq.empty() && count--)
    {
      res.push_back(pq.top().second);
      pq.pop();
    }

    return res;
  }

  void follow(int followerId, int followeeId)
  {
    following[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId)
  {
    following[followerId].erase(followeeId);
  }
};
