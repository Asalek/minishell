

## how To Use

run the following commands :

```bash
git clone https://github.com/Asalek/minishell.git
cd minishell
git clone https://github.com/Homebrew/brew ~/.brew
echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc
source $HOME/.zshrc
./brew_installer.bash
brew install openssl@1.1
brew install readline
make && clear
./minishell
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)