package main

import (
	"flag"
	"web_site/configs"
	"web_site/internal/app"
	"web_site/internal/handler"
	"web_site/internal/render"

	"log"
)

func main() {
	log.Println("wait a minute...")

	configPath := flag.String("config", "config.json", "path to config file")
	flag.Parse()

	cfg, err := configs.GetConfig(*configPath)
	if err != nil {
		log.Println(err)
		return
	}

	template, err := render.NewTemplateHTML(cfg.TemplateDir)
	if err != nil {
		log.Println(err)
		return
	}

	handler := handlers.NewHandler(template)

	err = app.Server(cfg, handler.Routes())

	if err != nil {

		log.Println("Ooopss...\n", err)
		return
	}
}
