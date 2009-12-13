/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_SIGNAL_OBJECT_HPP_INCLUDED
#define SGE_SIGNAL_OBJECT_HPP_INCLUDED

#include <sge/signal/detail/base.hpp>
#include <sge/signal/detail/base_impl.hpp>
#include <sge/signal/detail/operator_limit.hpp>
#include <sge/signal/detail/define_operator.hpp>
#include <sge/signal/detail/define_void_operator.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/preprocessor/repetition/repeat.hpp>
#include <boost/intrusive/list.hpp>
#include <boost/type_traits/is_void.hpp>
#include <boost/type_traits/function_traits.hpp>
#include <boost/utility/enable_if.hpp>

namespace sge
{
namespace signal
{

template<
	typename T,
	typename Enable = void
>
class object
:
	public detail::base<T>
{
public:
	typedef detail::base<T> base;
	typedef typename base::connection_list connection_list;
	typedef typename boost::function_traits<T>::result_type result_type;
	//typedef typename sge::function::object<T>::result_type result_type;
	typedef sge::function::object<result_type (result_type,result_type)> combiner_type;

	explicit object(
		combiner_type const &_combiner = boost::phoenix::arg_names::arg1)
	:
		combiner_(_combiner)
	{}

	void combiner(
		combiner_type const &_combiner)
	{
		combiner_ = _combiner;
	}

	SGE_SIGNAL_DETAIL_DEFINE_EMPTY_OPERATOR
	BOOST_PP_REPEAT(SGE_SIGNAL_DETAIL_OPERATOR_LIMIT,SGE_SIGNAL_DETAIL_DEFINE_OPERATOR,nil)
private:
	combiner_type combiner_;
};

template<
	typename T>
class object<
	T,
	typename boost::enable_if<
		boost::is_void<
			typename boost::function_traits<T>::result_type
		>
	>::type
>
:
	public detail::base<T>
{
public:
	typedef detail::base<T> base;
	typedef typename base::connection_list connection_list;

	SGE_SIGNAL_DETAIL_DEFINE_EMPTY_VOID_OPERATOR
	BOOST_PP_REPEAT(SGE_SIGNAL_DETAIL_OPERATOR_LIMIT,SGE_SIGNAL_DETAIL_DEFINE_VOID_OPERATOR,nil)
};

}
}

#endif
