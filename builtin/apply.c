	return !memcmp("/dev/null", str, 9) && isspace(str[9]);
	eol = strchr(line, '\n');
		char *s = xmalloc(root_len + strlen(patch->def_name) + 1);
		strcpy(s, root);
		strcpy(s + root_len, patch->def_name);
	patch->ws_rule = whitespace_rule(patch->new_name
					 ? patch->new_name
					 : patch->old_name);
		img->line = xrealloc(img->line, nr * sizeof(*img->line));
static int checkout_target(struct cache_entry *ce, struct stat *st)
		if (checkout_target(ce, &st))
			if (checkout_target(*ce, st))
	int fd;
				die("sha1 information is lacking or useless for submoule %s",
	fd = open(filename, O_WRONLY | O_CREAT, 0666);
	if (fd < 0 || write_index(&result, fd) || close(fd))
		const char *s = buf;
		if (get_sha1_hex(s + strlen("Subproject commit "), ce->sha1))
static struct string_list limit_by_name;
static int has_include;
static void add_name_limit(const char *name, int exclude)
{
	struct string_list_item *it;

	it = string_list_append(&limit_by_name, name);
	it->util = exclude ? NULL : (void *) 1;
}

static int use_patch(struct patch *p)
{
	const char *pathname = p->new_name ? p->new_name : p->old_name;
	int i;

	/* Paths outside are not touched regardless of "--include" */
	if (0 < prefix_length) {
		int pathlen = strlen(pathname);
		if (pathlen <= prefix_length ||
		    memcmp(prefix, pathname, prefix_length))
			return 0;
	}

	/* See if it matches any of exclude/include rule */
	for (i = 0; i < limit_by_name.nr; i++) {
		struct string_list_item *it = &limit_by_name.items[i];
		if (!wildmatch(it->string, pathname, 0, NULL))
			return (it->util != NULL);
	}

	/*
	 * If we had any include, a path that does not match any rule is
	 * not used.  Otherwise, we saw bunch of exclude rules (or none)
	 * and such a path is used.
	 */
	return !has_include;
}


static void prefix_one(char **name)
{
	char *old_name = *name;
	if (!old_name)
		return;
	*name = xstrdup(prefix_filename(prefix, prefix_length, *name));
	free(old_name);
}

static void prefix_patches(struct patch *p)
{
	if (!prefix || p->is_toplevel_relative)
		return;
	for ( ; p; p = p->next) {
		prefix_one(&p->new_name);
		prefix_one(&p->old_name);
	}
}

		if (prefix)
			prefix_patches(patch);
static int git_apply_config(const char *var, const char *value, void *cb)
	if (!strcmp(var, "apply.whitespace"))
		return git_config_string(&apply_default_whitespace, var, value);
	else if (!strcmp(var, "apply.ignorewhitespace"))
		return git_config_string(&apply_default_ignorewhitespace, var, value);
	return git_default_config(var, value, cb);
	git_config(git_apply_config, NULL);
		if (write_cache(newfd, active_cache, active_nr) ||
		    commit_locked_index(&lock_file))