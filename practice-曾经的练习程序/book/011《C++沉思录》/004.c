param = getfield(tf);
mode = cvlong(param, strlen(param), 8);

uid = numuid(getfield(tf));

gid = numgid(getfield(tf));

path = transname(getfield(tf));

geteol(tf);
