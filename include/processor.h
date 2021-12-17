  #ifndef __PROCESSOR__
#define __PROCESSOR__

class Processor {
  int busy_tacts;
  bool free;
public:
  Processor(int _busy_tacts = 0, bool _free = true) : busy_tacts(_busy_tacts), free(_free) {}
 // ~Processor();
  bool is_free();
  void decrease_tacts();
  void set_status();
  int get_busy_tacts();
  void set_busy_tacts(int tacts);
};


#endif