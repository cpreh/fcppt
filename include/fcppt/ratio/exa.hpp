#ifndef FCPPT_RATIO_EXA_HPP_INCLUDED
#define FCPPT_RATIO_EXA_HPP_INCLUDED

#include <fcppt/config.h>
#ifdef FCPPT_HAVE_LONG_LONG
#include <fcppt/ratio/object_fwd.hpp>

namespace fcppt
{
namespace ratio
{

typedef object<
	1000000000000000000LL,
	1
> exa;

}
}
#endif

#endif
