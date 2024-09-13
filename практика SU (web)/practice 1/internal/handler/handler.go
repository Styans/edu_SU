package handlers

import (
	"web_site/internal/render"
)

type Handler struct {
	templates render.TemplatesHTML
}

func NewHandler(tmlp render.TemplatesHTML) *Handler {
	return &Handler{
		templates: tmlp,
	}
}
