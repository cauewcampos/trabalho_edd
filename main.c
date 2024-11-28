#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int arrayNums1[100000];
int arrayNums2[100000];
int arrayNums3[100000];
int arrayNums4[100000];
double timeInsertion = 0;
double timeQuick = 0;
double timeBubble = 0;
double timeSelection= 0;

// vetor inicializado com 100 nomes diferentes.
char palavras[8000][800] = {
    "amor", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo", "brisa", "chuva", "dado", "energia",
    "felicidade", "garrafa", "história", "infinito", "jasmim",
    "karisma", "lua", "montanha", "natureza", "oceano",
    "paz", "quintal", "raio", "sorriso", "tempo",
    "universo", "vento", "xícara", "youtuber", "zen",
    "azul", "baleia", "chocolate", "dúvida", "esperança",
    "futuro", "globo", "honra", "ideia", "jovem",
    "kilo", "livro", "música", "nuvem", "orquídea",
    "praia", "qualidade", "rosa", "sonho", "trilha",
    "união", "vida", "xampu", "yeti", "ziguezague",
    "anel", "bicicleta", "caderno", "diamante", "estrela",
    "fogão", "galáxia", "herói", "ilha", "janela",
    "kiwi", "limonada", "mapa", "navio", "olho",
    "palhaço", "quadro", "rio", "sol", "tigre",
    "urso", "violão", "xarope", "safira", "tartaruga",
    "unicórnio", "violino", "xilofone", "zoológico", "diamante",
    "papagaio", "quadrado", "relâmpago", "energia", "esperança",
    "montanha", "neve", "oceano", "lua", "internet",
    "cachorro", "girassol", "elefante", "diamante", "energia",
    "alegria", "bandeira", "coração", "desafio", "explosão",
    "floresta", "guitarra", "hipnotizar", "imaginário", "jogo",
    "kiwi", "luz", "mundo", "notícia", "olhar",
    "paz", "quarto", "rosa", "serpente", "tempestade",
    "unidade", "vulcão", "tigre", "xícara", "yoga",
    "zebra", "água", "brilho", "café", "dólar",
    "elefante", "fogo", "gelo", "hipopótamo", "inimigo",
    "jovem", "lava", "mágico", "nevoeiro", "orvalho",
    "ponto", "quimono", "rato", "sol", "touro",
    "uva", "viagem", "xampu", "zangado", "alvo",
    "banco", "capitão", "dólar", "elefante", "futuro",
    "galáxia", "horizonte", "invisível", "jogador", "kamikaze",
    "lenda", "mestre", "nuvem", "oceano", "pioneiro",
    "quente", "relâmpago", "solução", "trovoada", "universo",
    "vazio", "zangado", "abóbora", "beijo", "coração",
    "dourado", "esmeralda", "fogo", "glória", "herói",
    "isolado", "jovem", "kilo", "luz", "mistério",
    "neve", "olho", "piano", "quadro", "rápido",
    "sol", "tesouro", "urso", "vulcão", "xaxim",
    "yeti", "zelador", "alvo", "borboleta", "caverna",
    "diamante", "elétrico", "fumaça", "gelo", "halo"
};

// função para criar um vetor com 50000 numeros aleatorios.
void criarNum(){
    for(int i = 0; i < 100000; i++){
        int num = rand() % 100000;
        arrayNums1[i] = num;
        arrayNums2[i] = num;
        arrayNums3[i] = num;
        arrayNums4[i] = num;
    }
}

// METODOS DE ORDENAÇÃO PARA NUMEROS
void insertionSort(int vet[], int tam) {

    clock_t start = clock();

    int i, j, aux;
        for (i = 1; i < tam; i++){
            aux = vet[i];
            j = i - 1;

            while((j >= 0) && (aux < vet[j])){
                vet[j+1] = vet[j];
                j--;
            }
            vet[j+1]= aux;
        }

    clock_t end = clock();
    timeInsertion = (double)(end - start) / CLOCKS_PER_SEC;

}

void selectionSort(int vet[], int tam) {

    clock_t start = clock();

    for (int i = 0; i < tam; i++) {
        int index_menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[index_menor])
                index_menor = j;
        }
        int aux = vet[i];
        vet[i] = vet[index_menor];
        vet[index_menor] = aux;
    }

    clock_t end = clock();
    timeSelection = (double)(end - start) / CLOCKS_PER_SEC;
}

void bubbleSort(int vet[], int tam) {

    clock_t start = clock();

    int i, j, aux;
    for (i = 1; i < tam; i++) {
        for (j = 0; j < tam - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }

    clock_t end = clock();
    timeBubble = (double)(end - start) / CLOCKS_PER_SEC;
}

// METODOS DE ORDENAÇÃO PARA STRING
void selectionSortWords(char vet[][800], int tam) {

    clock_t start = clock();

    for (int i = 0; i < tam - 1; i++) {
        int index_menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (strcmp(vet[j], vet[index_menor]) < 0) {
                index_menor = j;
            }
        }
        char temp[800];
        strcpy(temp, vet[i]);
        strcpy(vet[i], vet[index_menor]);
        strcpy(vet[index_menor], temp);
    }

    clock_t end = clock();
    timeSelection = (double)(end - start) / CLOCKS_PER_SEC;
}

// MOSTRAR OS TEMPOS
void showTimes(double x, double y,double z, double a) {
        printf(" ___________________________________ \n");
        printf("|       TEMPOS DE EXECUCAO          |\n");
        printf("| Insertion Sort: %f segundos |\n", x);
        printf("| Selection Sort: %f segundos |\n", y);
        printf("| Bubble Sort   : %f segundos |\n", z);
        printf("| Quick Sort    : %f segundos |\n", a);
        printf(" ___________________________________ \n\n");
        timeInsertion = 0;
        timeQuick = 0;
        timeBubble = 0;
        timeSelection= 0;
}



int main () {

    int resp = 0;

    while(resp!=3){
    printf("======================================================================\n");
    printf(" Voce deseja testar os metodos de ordenacao com numeros ou palavras?\n");
    printf(" 1 - Numeros\n 2 - Palavras\n 3 - Sair\n");
    printf("======================================================================\n");
    printf("Insira um numero: ");
    scanf("%d", &resp);


    if(resp==1){
            printf("\n");
            printf("Criando uma ordem de numeros aleatorios...\n\n");
            criarNum();
            insertionSort(arrayNums2,100000);
            printf("Ordenando os numeros...\n\n");
            insertionSort(arrayNums1,100000);
            selectionSort(arrayNums2,100000);
            bubbleSort(arrayNums1,100000);
            showTimes(timeInsertion,timeSelection,timeBubble,timeQuick);


    } else if(resp==2) {
        printf("\n");
        printf("Criando um array de nomes aleatorios...\n\n");
        printf("Ordenando os nomes...\n\n");
        selectionSortWords(palavras,8000);
        showTimes(timeInsertion,timeSelection,timeBubble,timeQuick);

    } else {
        printf("\nObrigado por utilizar o programa!\n");
    }
}

    return 0;
}

