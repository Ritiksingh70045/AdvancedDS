#include <bits/stdc++.h>
using namespace std;

// ---------------- Abstract Class ----------------
class MediaPlayer
{
public:
  virtual void play(const string &file) = 0;
  virtual ~MediaPlayer() {}
};

// ---------------- MP3 Player ----------------
class MP3Player : public MediaPlayer
{
public:
  void play(const string &file) override
  {
    cout << "Playing MP3 file: " << file << endl;
  }
};

// ---------------- MP4 Player ----------------
class MP4Player : public MediaPlayer
{
public:
  void play(const string &file) override
  {
    cout << "Playing MP4 file: " << file << endl;
  }
};

// ---------------- VLC Player ----------------
class VLCPlayer : public MediaPlayer
{
public:
  void play(const string &file) override
  {
    cout << "Playing VLC file: " << file << endl;
  }
};

// ---------------- Main ----------------
int main()
{
  vector<MediaPlayer *> players;

  players.push_back(new MP3Player());
  players.push_back(new MP4Player());
  players.push_back(new VLCPlayer());

  vector<string> files = {"song.mp3", "video.mp4", "movie.vlc"};

  for (int i = 0; i < players.size(); i++)
  {
    players[i]->play(files[i]);
  }

  // cleanup
  for (auto p : players)
  {
    delete p;
  }
}