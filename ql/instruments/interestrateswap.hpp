#ifndef quantlib_interest_rate_swap_hpp
#define quantlib_interest_rate_swap_hpp

#include <ql/instruments/swap.hpp>
#include <ql/time/daycounter.hpp>

namespace QuantLib {

    class IborIndex;

    class InterestRateSwap : public Swap {
      public:
        enum Type { Receiver = -1, Payer = 1 };

        virtual Type type() const = 0;
        virtual Real nominal() const = 0;

        virtual Rate fixedRate() const = 0;
        virtual const DayCounter& fixedDayCount() const = 0;

        virtual ext::shared_ptr<IborIndex> floatingIndex() const = 0;

        virtual Spread spread() const = 0;

        virtual const Leg& fixedLeg() const = 0;
        virtual const Leg& floatingLeg() const = 0;

        virtual Real fixedLegBPS() const = 0;
        virtual Real fixedLegNPV() const = 0;
        virtual Rate fairRate() const = 0;

        virtual Real floatingLegBPS() const = 0;
        virtual Real floatingLegNPV() const = 0;

        virtual Spread fairSpread() const = 0;

      protected:
        InterestRateSwap(Size legs) : Swap(legs) {}
    };

}

#endif
