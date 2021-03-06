#ifndef INCLUDE_AVIONICS_H
#define INCLUDE_AVIONICS_H


#include "../AvionicsBase/AvionicsBase.h"


class Avionics : public AvionicsBase
{
  //Modules

public:
  Avionics(bool imuFilter = true, bool useMagnInMadgwick = false)
      : AvionicsBase(true, imuFilter, useMagnInMadgwick)
  {
  }

  virtual bool initialize() override;

  virtual void setDebugMode(bool mode) override
  {
  }

private:
  virtual void update() override;

  virtual void end() override;

  virtual void reboot() override
  {
  }

  virtual bool isReady(bool showDetail = true) override;

  virtual void getDatas() override;

  virtual void writeDatas() override;

  virtual void transmit(const xString &str) override
  {
  };

  virtual xString received() override
  {
    return xString();
  };

  virtual void closeSDCard() override{
  }

  void onReceive(){
  }
};


#endif