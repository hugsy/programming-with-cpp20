// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class StockIndex {
  std::string mName{};
  double      mLastPoints{};
  double      mPoints{};

public:
  StockIndex(std::string name)
  : mName{name}
  {}

  std::string name() const { return mName; }

  void setPoints(double points)
  {
    mLastPoints = mPoints;
    mPoints     = points;
  }

  double points() const { return mPoints; }

  double pointsDiff() const { return mPoints - mLastPoints; }

  double pointsPercent() const
  {
    if(0.0 == mLastPoints) { return 0.0; }
    return (mPoints - mLastPoints) / mLastPoints * 100.0;
  }
};

std::vector<StockIndex> GetIndices()
{
  StockIndex dax{"DAX"};
  dax.setPoints(13'052.95);
  dax.setPoints(13'108.50);

  StockIndex dow{"Dow"};
  dow.setPoints(29'080.17);
  dow.setPoints(29'290.00);

  StockIndex sp{"S&P 500"};
  sp.setPoints(3'537.01);
  sp.setPoints(3'561.50);

  return {dax, dow, sp};
}

int main()
{
  for(const auto& index : GetIndices()) {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    std::cout.imbue(std::locale("de_DE.UTF-8"));  // #A Apply the desired locale

    std::cout << std::setw(10) << std::left << index.name() << "  "
              << std::setw(8) << std::right << index.points() << "  "
              << std::setw(6) << index.pointsDiff() << " "
              << index.pointsPercent() << '%' << '\n';
  }
}