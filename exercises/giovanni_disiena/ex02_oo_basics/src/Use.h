#ifndef USE_H
#define USE_H

class Use {
public:
  Use();
  Use(const Use &u);
  ~Use();
  Use &operator=(const Use &);
  operator size_t() const;

private:
  unsigned *m_refCount;
};

#endif // USE_H