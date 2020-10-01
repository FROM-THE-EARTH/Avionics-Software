#include "AircraftBase.h"
#include "IM920Wrapper.h"
#include "LPSWrapper.h"
#include "LSMWrapper.h"
#include "mbed.h"

using AircraftForMbed = AircraftWrapper<Kernel::Clock>;

template<class T> class AircraftWrapper : public AircraftBase {
protected:
  std::chrono::time_point<T> bootTime;
  std::chrono::time_point<T> nowTime;
  std::chrono::time_point<T> preTime;
  //Kernel::Clock::time_point bootTime;
  //Kernel::Clock::time_point nowTime;
  //Kernel::Clock::time_point preTime;

  // modules
  IM920Wrapper *receiver_, *transmitter_;
  LPSWrapper *lps_;
  LSMWrapper *lsm_;

  Commands commands_ = Commands::None;

  AircraftWrapper(IM920Wrapper *receiver, IM920Wrapper *transmitter,
                   LPSWrapper *lps, LSMWrapper *lsm)
      : AircraftBase(),
        receiver_(receiver), transmitter_(transmitter), lps_(lps), lsm_(lsm) 
        {}

  // set launch condition
  virtual bool launchCondition() = 0;

  // set detaching condition
  virtual bool detachCondition() = 0;

  // set opening parachute condition
  virtual bool decelerationCondition() = 0;

  // set landing condition
  virtual bool landingCondition() = 0;

  // detaching operation
  virtual void detachAircraft() = 0;

  // opening parachute operation
  virtual void openParachute() = 0;

public:
  virtual bool initialize() override;

  virtual void setDebugMode(bool mode) override {
    transmitter_->setSendToSerial(mode);
    receiver_->setSendToSerial(mode);
  }

private:
  virtual void update() override;

  virtual bool isReady(bool showDetail = false) override;

  virtual void end() override;

  virtual void waiting() override;

  virtual void waitingLaunch() override;

  virtual void inFlight() override;

  virtual void landing() override;

  virtual void getDatas() override;

  virtual void writeDatas() override;

  virtual void onReceive() override;
};