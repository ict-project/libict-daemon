# `ict::daemon` module

Provides the functions for a daemon application.

## Usage

Following functions are available:
* `ict::daemon::daemonize(log=false)` - Converts process into system daemon (optionally syslog is used);
* `ict::daemon::savePid(pid,path)` - Saves PID into given file.
