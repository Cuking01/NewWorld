#pragma once

struct Handle
{
	Scene*scene;
	u2 key;
	operator People* () const;
	operator u2 () const;
};
