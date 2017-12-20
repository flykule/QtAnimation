#ifndef FILTERLOADER_H
#define FILTERLOADER_H

#include <Filter.h>
#include <memory>
#include <vector>

class FilterLoader {
public:
  FilterLoader();
  void loadFilters();
  const std::vector<std::unique_ptr<Filter>> &filters() const;

private:
  std::vector<std::unique_ptr<Filter>> mFilters;
};

#endif // FILTERLOADER_H
