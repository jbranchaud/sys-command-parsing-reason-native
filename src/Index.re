let run = () => {
  /* open a process executing the 'pwd' command */
  let process_in_channel = Unix.open_process_in("pwd");

  /* read first line of the input channel handler */
  let process_string = Pervasives.input_line(process_in_channel);

  /* parse the command output */
  let path_parts = Str.split(Str.regexp("/"), process_string);
  let base_dir = List.hd(List.rev(path_parts));

  print_endline(Printf.sprintf("Base Dir: %s", base_dir));

  /* cleanup by closing input channel */
  Unix.close_process_in(process_in_channel);
};

run();