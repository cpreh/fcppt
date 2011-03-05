#ifndef FCPPT_IO_RAW_CONTAINER_SOURCE_HPP_INCLUDED
#define FCPPT_IO_RAW_CONTAINER_SOURCE_HPP_INCLUDED

#include <fcppt/shared_ptr.hpp>
#include <fcppt/class_symbol.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/container/raw_vector_decl.hpp>
#include <boost/iostreams/concepts.hpp>
#include <ios>
#include <streambuf>

namespace fcppt
{
namespace io
{
class FCPPT_CLASS_SYMBOL raw_container_source
{
public:
	typedef
	char
	char_type;

	struct category
	:
		boost::iostreams::input_seekable,
		boost::iostreams::device_tag
	{
	};

	typedef
	fcppt::container::raw_vector<char>
	container;

	typedef
	fcppt::shared_ptr<container>
	container_ptr;

	typedef
	container::const_iterator
	const_iterator;

	FCPPT_SYMBOL explicit
	raw_container_source(
		char const *,
		char const *);

	FCPPT_SYMBOL std::streamsize
	read(
		char *,
		std::streamsize);

	FCPPT_SYMBOL std::streampos 
	seek(
		boost::iostreams::stream_offset,
		std::ios_base::seekdir);
private:
	container_ptr const chars_;
	const_iterator pos_;
};
}
}

#endif
