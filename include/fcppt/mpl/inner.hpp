//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_INNER_HPP_INCLUDED
#define FCPPT_MPL_INNER_HPP_INCLUDED

namespace fcppt
{
namespace mpl
{

/// Applies <code>::%type</code> on \p Type
template<
	typename Type
>
struct inner
{
	typedef typename Type::type type;
};

}
}

#endif
