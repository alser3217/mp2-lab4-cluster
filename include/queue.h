#ifndef __QUEUE__
#define __QUEUE__

#define MAX_QUEUE_SIZE 50

template<typename T>
class TQueue {
  int queue_size;
  int top = -1;
  int bottom = 0;
  T* data;
public:
  TQueue(int _queue_size) : queue_size(_queue_size) {
    if (_queue_size < 0 || _queue_size > MAX_QUEUE_SIZE)
      throw "Wrong queue size.";
    data = new T[queue_size];
  }
  TQueue(const TQueue& object) = delete;
  ~TQueue();
  int size();
  T front();
  T pop();
  void push(const T& object);
  int current_size();
  bool is_empty();
  bool is_full();
  void operator=(const TQueue& object) = delete;
};

template <typename T>
TQueue<T>::~TQueue() {
  delete[] data;
}

template<typename T>
int TQueue<T>::size() {
  return queue_size;
}

template <typename T>
int TQueue<T>::current_size() {
  return (top - bottom + 1);
}

template <typename T>
T TQueue<T>::front() {
  return data[bottom % queue_size];
}

template <typename T>
void TQueue<T>::push(const T& object) {
  data[++top % queue_size] = object;
}

template <typename T>
T TQueue<T>::pop(){
  return data[bottom++ % queue_size];
}

template <typename T>
bool TQueue<T>::is_empty() {
  return (top - bottom + 1) == 0;
}

template <typename T>
bool TQueue<T>::is_full() {
  return (top - bottom + 1) == queue_size;
}
#endif